#include "phics.h"
#define MAX_PATH 256
/**
 * _getline - get the line command
 * @ptr: null terminated char *
 * @n: 0
 * @stm: source
 *
 * Return: characters read or -1
 */
ssize_t _getline(char **ptr, __attribute__((unused)) size_t *n, FILE *stm)
{
	char buff[MAX_PATH] = "";
	ssize_t read_count = 0;

	read_count = read(fileno(stm), buff, MAX_PATH);
	if (read_count == 0 || read_count == -1)
	{
		return (-1);
	}
	*ptr = malloc(sizeof(char) * MAX_PATH);
	_strcpy(*ptr, buff);
	return (read_count);
}
