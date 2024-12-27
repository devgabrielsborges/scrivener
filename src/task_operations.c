#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task_operations.h"
#include "task.h"


void create_task(char *task_name, char *date, int task_priority){
  Task *new_task = (Task *)malloc(sizeof(Task));

  new_task->task_name = task_name;
  new_task->date = date;
  new_task->task_priority = task_priority;

  // writing to binary file to store the task
  FILE *file = fopen(".tasks.bin", "ab");
  fwrite(new_task, sizeof(Task), 1, file);
  fclose(file);

}


void visualize_tasks()
{
  FILE *file = fopen(".tasks.bin", "rb");

  Task *new_task = (Task *)malloc(sizeof(Task));
  
  while(fread(new_task, sizeof(Task), 1, file)){
    printf("%s | %i | %s",
           new_task->task_name, new_task->task_priority, new_task->date);
    printf("\n");
  }

  fclose(file);
}


void fetch_task(char *task_name, char *info, int type){
  FILE *file = fopen(".tasks.bin", "ab");

  Task *new_task = (Task *)malloc(sizeof(Task));

  while(fread(new_task, sizeof(Task), 1, file)){
    if(strcmp(new_task->task_name, task_name) == 0){
      FILE *file = fopen(".tasks.bin", "wb+"); 

      switch (type)
      {
        case 1:
          new_task->task_name = info;

          fwrite(new_task, sizeof(Task), 1, file);
          fclose(file);

          printf("Task name updated successfully\n");
          break;

        case 2:
          new_task->date = info;

          fwrite(new_task, sizeof(Task), 1, file);
          fclose(file);

          printf("Date updated successfully\n");
          break;

        case 3:
          new_task->task_priority = atoi(info);

          fwrite(new_task, sizeof(Task), 1, file);
          fclose(file);

          printf("Priority updated successfully\n");
          break;

        default:
          printf("Invalid type\n");
          fclose(file);
          return;
      }
    }

    printf("Task not found\n");
    fclose(file);
  }
}

void delete_task(char *task_name)
{
  FILE *file = fopen(".tasks.bin", "ab");

  Task *new_task = (Task *)malloc(sizeof(Task));

  while(fread(new_task, sizeof(Task), 1, file)){
    if(strcmp(new_task->task_name, task_name) == 0){
      // writing to binary file to store the task
      FILE *file = fopen(".tasks.bin", "ab");

      // deleting task
      fwrite(new_task, sizeof(Task), 1, file);
      fclose(file);

      printf("Task deleted successfully\n");
      return;
    }
  }

  printf("Task not found\n");
  fclose(file);
}
