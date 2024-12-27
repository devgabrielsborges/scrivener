#include "menu.h"

#include <stdio.h>
#include <stdlib.h>

void help(){
    printf("Usage: task_manager [OPTION] [ARGS...]\n");
    printf("Options:\n");
    printf("  -h                Show this help message\n");
    printf("  -i <task> <date> <prio>  Add a new task with name <task> and date <date> with the priority <prio> \n");
    printf("  -v                View all tasks\n");
    printf("  -u <old> <new>    Update task name from <old> to <new>\n");
    printf("  -d <task>         Delete task with name <task>\n");
}


void clear_screen(){
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
