#include <string.h>

#include "task_operations.h"
#include "menu.h"


int main(int argc, char *argv[])
{
  if (argc < 3 || argc > 5)
  {
    help();
    return 1;
  }

  if (strlen(argv[2]) <= 0)
  {
    help();
    return 2;
  }


  if (strcmp(argv[1], "-i") == 0)
  {
    create_task(argv[2], argv[3],(int) argv[4]);
  }

  else if (strcmp(argv[1], "-v") == 0)
  {
    visualize_tasks();
  }

  else if (strcmp(argv[1], "-f"))
  {
    fetch_task(argv[2], argv[4],(int) argv[3]); 
  }

  else if (strcmp(argv[1], "-d") == 0)
  {
    delete_task(argv[2]);
  }

  else
  {
    help();
  }

}
