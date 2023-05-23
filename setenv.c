#include "phics.h"
int _setenv(const char *name, const char *value, int overwrite)
{
	char **newenv = environ, newvar[1024];
	int newenv_length = 0;
	char *valuecpy = strdup(value);
	int count = 0;

	if (getenv(name) != NULL && overwrite == 0)
	{
		free(valuecpy);
		return (0);
	}
	else if (getenv(name) == NULL)
	{

		for (newenv_length = 0; environ[newenv_length]; newenv_length++)
			;
		newvar[0] = '\0';
		strcat(newvar, name);
		strcat(newvar, "=");
		strcat(newvar, value);
		newenv[newenv_length] = newvar;
		newenv[newenv_length + 1] = NULL;
		free(valuecpy);
		return (0);
	}

	else if (getenv(name) && overwrite != 0)
	{
		for ( ; strncmp(*(newenv), name, strlen(name)) != 0; newenv++)
			count++;
		if(*(*(newenv) + strlen(name)) == '=') 
		{
			strcpy((*(newenv) + strlen(name) + 1), valuecpy);
		}
		environ = newenv - count;
		free(valuecpy);
		return (0);
	}
	return (-1);
}

/**int main(int argc, char **argv)
{
	int i = 0;

	_setenv("DDCHURA", "/ls", 0);
	_setenv("PATH", "/hls", 1);
	for (i = 0; *(environ + i) != NULL; i++)
	{
		printf("%s\n", *(environ + i));
	}
}*/
