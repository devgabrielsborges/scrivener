from libc.stdlib cimport atoi
from libc.string cimport strcmp
from libc.stdio cimport printf
from gcalendar.py import *

cdef extern from "task_operations.h":
    void create_task(const char* arg1, const char* arg2, int arg3)
    void fetch_task(const char* arg1, const char* arg2, const char* arg3, int arg4)
    void delete_task(const char* arg1)
    void visualize_tasks()

cdef extern from "menu.h":
    void help()

def main(int argc, list argv):
    if argc == 1 or argv[1] is None or strcmp(argv[1].encode(), b"-h") == 0 or strcmp(argv[1].encode(), b"--help") == 0:
        help()
        return 0

    elif strcmp(argv[1].encode(), b"-i") == 0 and argc == 5:
        create_task(argv[2].encode(), argv[3].encode(), atoi(argv[4].encode()))

    elif strcmp(argv[1].encode(), b"-v") == 0:
        visualize_tasks()

    elif strcmp(argv[1].encode(), b"-u") == 0 and argc == 6:
        fetch_task(argv[2].encode(), argv[3].encode(), argv[4].encode(), atoi(argv[5].encode()))

    elif strcmp(argv[1].encode(), b"-d") == 0 and argc == 3:
        delete_task(argv[2].encode())

    else:
        printf(b"Invalid usage\n\n")
        help()
        return 1

if __name__ == "__main__":
    import sys
    main(len(sys.argv), sys.argv)
