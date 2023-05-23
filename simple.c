#include "phics.h"
#define MAXCHAR 1024
/**
* main - main entry point
* @argc: argument count
* @argv: argument array
* @envp : env variables array
* Return: returns (0)
*/

int main(__attribute__((unused)) int argc, char **argv, char **envp)
{
	char *cmd = NULL, *delim = " \n", *args[200], *fullpath, **env = envp;
	int i = 0, cmdresult;
	size_t n = 0;
	pid_t pid;
	ssize_t read = 0;
	char filepath[MAXCHAR];
	int interactive = isatty(fileno(stdin));

	while (1)
	{
		if (interactive)
		{
			write(1, "$ ", 2);
			fflush(stdout);
		}
		if(cmd != NULL)
			free(cmd);
		read = _getline(&cmd, &n, stdin);
		if (read == -1)
			break;
		args[i] = strtok(cmd, delim);
		if (args[i] == NULL)
			continue;
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, delim);
		}
		args[i] = NULL;
		i = 0;
		cmdresult = handle_cmd(args, argv[0], cmd);
		if (cmdresult == 1)
		{
			continue;
		}
		fullpath = find_file_in_path(args[0], filepath);
		if (fullpath == NULL)
		{
			perror(argv[0]);
			continue;
		}
		pid = fork();
		do_pid(pid, cmd, fullpath, args, env);
	}
		return (0);
}
