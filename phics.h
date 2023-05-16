#ifndef PHICS_H
#define PHICS_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
char *find_file_in_path(char *filename, char *filepath);
void handle_pid(pid_t pid, char *cmd, char *fullpath, char *args[]);
#endif
