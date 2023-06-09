#include "phics.h"
/**
 * cd_dir - change directory
 * @argv: caller
 * @name: name of dir
 *
 * Return: 0
 */
int cd_dir(char *name, char *argv)
{
	int cd_checker;
	char buff[1024];

	if (name == NULL)
	{
		chdir(getenv("HOME"));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", getenv("HOME"), 1);
		return (0);
	}
	else if (_strcmp("-", name) == 0)
	{
		chdir(getenv("OLDPWD"));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", getcwd(buff, 1024), 1);
		return (0);
	}
	else
	{
		cd_checker = chdir(name);
		if (cd_checker == -1)
		{
			perror(argv);
			return (0);
		}
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", getcwd(buff, 1024), 1);
		return (0);
	}
	return (0);
}
