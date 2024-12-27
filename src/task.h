#ifndef TASK_H
#define TASK_H  

#include <stdlib.h>

typedef struct task {
    char task_name[256];
    char date[64];
    int task_priority;
} Task;

#endif // !TASK.H
