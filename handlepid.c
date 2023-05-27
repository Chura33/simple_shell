#include "phics.h"
/**
* do_pid - function that handles the execution of the full path
* @pid: the pid of the forked process
* @cmd: the first token entered in the command line
* @fullpath: the full path of the command
* @args: the array of the command and the arguments
* @env: environmental variable
*
* Return: returns void
*/
void do_pid(pid_t pid, char *cmd, char *fullpath, char *args[], char **env)
{
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0 && fullpath != NULL)
	{
		execve(fullpath, args, env);
		perror("execve");
		free(cmd);
		exit(2);
	}
	else
	{
		wait(NULL);
	}
}
