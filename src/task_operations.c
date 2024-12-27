#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task_operations.h"
#include "task.h"

void create_task(char *task_name, char *date, int task_priority) {
    Task new_task;

    // Copy strings into the fixed-size arrays
    strncpy(new_task.task_name, task_name, sizeof(new_task.task_name) - 1);
    new_task.task_name[sizeof(new_task.task_name) - 1] = '\0';  // Ensure null-termination

    strncpy(new_task.date, date, sizeof(new_task.date) - 1);
    new_task.date[sizeof(new_task.date) - 1] = '\0';  // Ensure null-termination

    new_task.task_priority = task_priority;

    // Write the structure directly to the binary file
    FILE *file = fopen("../data/.tasks.bin", "ab");
    if (!file) {
        perror("Failed to open the file");
        return;
    }
    printf("Creating Task: %s | %s | %i\n", new_task.task_name, new_task.date, new_task.task_priority);

    fwrite(&new_task, sizeof(Task), 1, file);
    fclose(file);
}


void visualize_tasks() {
    FILE *file = fopen("../data/.tasks.bin", "rb");
    if (!file) {
        perror("Failed to open the file");
        return;
    }

    Task new_task;
    while (fread(&new_task, sizeof(Task), 1, file)) {
        printf("%s | %s | %i\n", new_task.task_name, new_task.date, new_task.task_priority);
    }

    fclose(file);
}


void fetch_task(char *task_name, char *new_task_name, char *new_date, int new_priority) {
    FILE *file = fopen("../data/.tasks.bin", "rb+"); // Open file for reading and writing
    if (!file) {
        perror("Failed to open the file");
        return;
    }

    Task task;
    while (fread(&task, sizeof(Task), 1, file)) {
        if (strcmp(task.task_name, task_name) == 0) {
            // Update the task details
            strncpy(task.task_name, new_task_name, sizeof(task.task_name) - 1);
            task.task_name[sizeof(task.task_name) - 1] = '\0';

            strncpy(task.date, new_date, sizeof(task.date) - 1);
            task.date[sizeof(task.date) - 1] = '\0';

            task.task_priority = new_priority;

            // Move the file pointer back to overwrite the task
            fseek(file, -sizeof(Task), SEEK_CUR);
            fwrite(&task, sizeof(Task), 1, file);

            printf("Task updated successfully\n");
            fclose(file);
            return;
        }
    }

    printf("Task not found\n");
    fclose(file);
}


void delete_task(char *task_name) {
    FILE *file = fopen("../data/.tasks.bin", "rb"); // Open original file for reading
    if (!file) {
        perror("Failed to open the file");
        return;
    }

    FILE *temp_file = fopen(".tasks_temp.bin", "wb"); // Open temporary file for writing
    if (!temp_file) {
        perror("Failed to create temporary file");
        fclose(file);
        return;
    }

    Task task;
    int task_found = 0;

    // Read tasks one by one from the original file
    while (fread(&task, sizeof(Task), 1, file)) {
        if (strcmp(task.task_name, task_name) == 0) {
            task_found = 1; // Mark task as found
            continue;       // Skip this task to delete it
        }
        fwrite(&task, sizeof(Task), 1, temp_file); // Write all other tasks to the temp file
    }

    fclose(file);
    fclose(temp_file);

    if (task_found) {
        // Replace the original file with the temporary file
        remove("../data/");
        rename(".tasks_temp.bin", "../data/.tasks.bin");
        printf("Task deleted successfully\n");
    } else {
        // Clean up temporary file if no task was found
        remove(".tasks_temp.bin");
        printf("Task not found\n");
    }
}

