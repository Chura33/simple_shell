#include "phics.h"
/**
* handle_cmd - this checks for special commands
* @cmd: the command
* Return: returns void
*/
int handle_cmd(char **args, char *argv, char *cmd)
{
	int i = 0, result = 0, exit_status = 0;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (args[1] !=  NULL)
		{
			exit_status = atoi(args[1]);
			free(cmd);
			exit(exit_status);
		}
		free(cmd);
		exit(exit_status);
	}

	else if (_strcmp(args[0], "setenv") == 0)
	{
		result = set(args[1], args[2]);
		free(cmd);
		if (result == 0)
		printf("success\n");
		return (result);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		cd_dir(args[1], argv);
		return (1);
	}
	return (0);
}
