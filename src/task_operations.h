#ifndef TASK_OPERATIONS_H
#define TASK_OPERATIONS_H

#include "task.h"

void get_current_date(char *date);

void create_task(char *task_name, char *date, int task_priority);
void visualize_tasks();
void fetch_task(char *task_name, char *info, int type);
void fetch_task_priority(char *task_name, int new_priority);
void delete_task(char *task_name);

#endif // !TASK_OPERATIONS_H
