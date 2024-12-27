#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "task_operations.h"
#include "menu.h"


int main(int argc, char *argv[])
{
  if (argc == 1 || argv[1] == NULL ||strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
  {
    help();
    return 0;
  }

  else if (strcmp(argv[1], "-i") == 0 && argc == 5)
  {
    create_task(argv[2], argv[3], atoi(argv[4]));
  }

  else if(strcmp(argv[1], "-v") == 0)
  {
    visualize_tasks();
  }

  else if(strcmp(argv[1], "-u") == 0 && argc == 6)
  {
    fetch_task(argv[2], argv[3], argv[4], atoi(argv[5]));
  }

  else if(strcmp(argv[1], "-d") == 0 && argc == 3)
  {
    delete_task(argv[2]);
  }

  else
  {
    printf("Invalid usage\n\n");
    help();
    return 1;
  }

}
