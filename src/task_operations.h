#ifndef TASK_OPERATIONS_H
#define TASK_OPERATIONS_H

#include "task.h"

void get_current_date(char *date);

void create_task(char *task_name, char *date, int task_priority);
void visualize_tasks();
void fetch_task(char *task_name, char *new_task_name, char *new_date, int new_priority);
void fetch_task_priority(char *task_name, int new_priority);
void delete_task(char *task_name);

#endif // !TASK_OPERATIONS_H
