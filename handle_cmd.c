#include "phics.h"
/**
* handle_cmd - this checks for special commands
* @cmd: the command
* Return: returns void
*/
int handle_cmd(char *cmd)
{
	int i = 0, result = 0;
	char *delim = " \n", *newArgs[256] = {NULL}, *cmdcpy = strdup(cmd);

	newArgs[i] = strtok(cmdcpy, delim);

	while (newArgs[i] != NULL)
	{
		i++;
		newArgs[i] = strtok(NULL, delim);
	}
	newArgs[i] = NULL;
	if (_strncmp(cmd, "exit\n", _strlen(cmd)) == 0)
	{
		free(cmdcpy);
		free(cmd);
		exit(EXIT_SUCCESS);
	}

	else if (strncmp(cmdcpy, "setenv",strlen("setenv")) == 0)
	{
		result = set(newArgs[1], newArgs[2]);
		free(cmdcpy);
		free(cmd);
		if (result == 0)
		printf("success\n");
		return (result);
	}
	free(cmdcpy);	
	return (1);
}
