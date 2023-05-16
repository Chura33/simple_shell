#include "phics.h"
#define MAXCHAR 1024
/**
* main - main entry point
* Return: returns (0)
*/

int main(void)
{
	char *cmd = NULL, *delim = " \n", *args[200];
	int i = 0;
	size_t n = 0;
	pid_t pid;
	ssize_t read = 0;
	char filepath[MAXCHAR];
	int interactive = isatty(fileno(stdin));
	char *fullpath;

	while (1)
	{
		if (interactive)
		{
			write(1, "$ ", 2);
			fflush(stdout);
		}
		read = getline(&cmd, &n, stdin);
		if (read == -1)
			break;
		args[i] = strtok(cmd, delim);
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, delim);
		}
		args[i] = NULL;
		i = 0;
		fullpath = find_file_in_path(args[0], filepath);
		pid = fork();
		handle_pid(pid, cmd, fullpath, args);
	}
		free(cmd);
		return (0);
}
