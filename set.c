#include "phics.h"
extern char **environ;
int set (char *name, char *value)
{
        char **newenv;
        char *newvar;
        int count = 0;

        if (getenv(name) == NULL)
        {
                for (count = 0; environ[count]; count++)
                        ;
                newenv = malloc(sizeof(char *) * (count + 2));
                newvar = malloc(sizeof(char) * (strlen(name) + strlen(value) + 2));

                for (count =0; environ[count]; count++)
                {
                        newenv[count] = strdup(environ[count]);
                }
                newenv[count] = newvar;
                newenv[count + 1] = NULL;
                newvar[0] = '\0';
                strcat(newvar, name);
                strcat(newvar, "=");
                strcat(newvar, value);

                for (count = 0; newenv[count]; count++)
                {
                        environ[count] = strdup(newenv[count]);
                }
                environ[count] = NULL;


                for (count = 0; newenv[count]; count++)
                {
                        free(newenv[count]);
                }
                free(newenv);
                return (0);
        }
	return (0);
}
