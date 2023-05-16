#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAXCHAR 256

/**
* find_file_in_path - finds the fullpath
* @filename: command name
* @filepath: char array
* Return: char *(success) NULL (failure)
*/
char *find_file_in_path(char *filename, char *filepath)
{
	char path[MAXCHAR];
	char *envpath = getenv("PATH");
	char *copy = strcpy(path, envpath);
	char *tok = strtok(path, ":");
	int i = 0;
	int j = 0;

	if (access(filename, X_OK) != -1)
	{
		copy = NULL;
		return (filename);
	}

	while (tok != NULL)
	{
		if (strlen(tok) + strlen(filename) + 2 <= MAXCHAR)
		{
			for (i = 0; i < strlen(tok); i++)
			{
				filepath[i] = tok[i];
			}
				filepath[i] = '/';

			for (j = 0; j < strlen(filename); j++)
			{
				filepath[i + j + 1] = filename[j];
			}
				filepath[i + j + 1] = '\0';

			if (access(filepath, X_OK) != -1)
			{
				return (filepath);
			}
		}

			tok = strtok(NULL, ":");
	}
		return (NULL);
}
