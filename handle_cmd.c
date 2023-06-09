#include "phics.h"
/**
* handle_cmd - this checks for special commands
* @cmd: the command
* @args: array pointer
* @argv: caller
* @cmd: command
*
* Return: returns void
*/
int handle_cmd(char **args, char *argv, char *cmd)
{
	int exit_status = 0;

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
		if (args[3] == NULL)
		{
			setenv(args[1], args[2], 0);
		}
		else if(args[2] == NULL)
		{
			setenv(args[1],"",1);
		}
		else
		{
			 setenv(args[1], args[2], atoi(args[3]));
		}
		free(cmd);
		return (1);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		cd_dir(args[1], argv);
		free(cmd);
		return (1);
	}
	return (0);
}
