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
	char *cmd = NULL, filepath[MAXCHAR], *args[200], *fullpath, **env = envp;
	char err[1024];
	int i = 0, interactive = isatty(fileno(stdin));
	size_t n = 0;
	pid_t pid;

	while (1)
	{
		if (interactive)
		{
			write(1, "$ ", 2);
			fflush(stdout);
		}
		if (cmd != NULL)
			free(cmd);
		if (_getline(&cmd, &n, stdin) == -1)
			break;
		i = 0;
		args[i] = strtok(cmd, " \t\n");
		if (args[i] == NULL)
			continue;
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " \t\n");
		}
		args[i] = NULL;
		err_msg(argv[0], args[0], err);
		if (handle_cmd(args, argv[0], cmd) == 1)
			continue;
		fullpath = find_file_in_path(args[0], filepath);
		if (fullpath == NULL)
		{
			perror(err);
			continue;
		}
		pid = fork();
		do_pid(pid, cmd, fullpath, args, env);
	}
		return (0);
}
