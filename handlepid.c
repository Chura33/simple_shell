#include "phics.h"
/**
* handle_pid - function that handles the execution of the full path
* @pid: the pid of the forked process
* @cmd: the first token entered in the command line
* @fullpath: the full path of the command
* @args: the array of the command and the arguments
* Return: returns void
*/
void handle_pid(pid_t pid, char *cmd, char *fullpath, char *args[])
{
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0 && fullpath == NULL)
	{
		execve(args[0], args, NULL);
		perror("execve");
		free(cmd);
		exit(0);
	}

	else if (pid == 0 && fullpath != NULL)
	{
		execve(fullpath, args, NULL);
		perror("execve");
		free(cmd);
		exit(0);

	}
	else
		wait(NULL);
}
