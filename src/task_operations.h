#ifndef TASK_OPERATIONS_H
#define TASK_OPERATIONS_H

#include "task.h"

void get_current_date(char *date);
void get_tasks_file_path(char *buffer,const size_t size);
void create_task(const char *task_name, const char *date, const int task_priority);
void visualize_tasks();
void fetch_task(const char *task_name,const char *new_task_name, const char *new_date, const int new_priority);
void fetch_task_priority(const char *task_name, const int new_priority);
void delete_task(const char *task_name);

#endif // !TASK_OPERATIONS_H
