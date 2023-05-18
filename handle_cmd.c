#include "phics.h"
/**
* handle_cmd - this checks for special commands
* @cmd: the command
* Return: returns void
*/

int handle_cmd(char *cmd)
{
	if (_strncmp(cmd, "exit\n", _strlen(cmd)) == 0)
	{
		return (-1);
	}
	return (0);
}
