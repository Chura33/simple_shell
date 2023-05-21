#include "phics.h"
#define MAX_PATH 256
/**
 * _getline - get the line command
 * @lineptr: null terminated char *
 * @n: 0
 * @stream: source
 *
 * Return: characters read or -1
 */
ssize_t _getline(char **lineptr, __attribute__((unused)) size_t *n, FILE *stream)
{
	char buff[MAX_PATH] = "";
	ssize_t read_count = 0;
	*lineptr = malloc(sizeof(char) *MAX_PATH);
	read_count = read(fileno(stream), buff, MAX_PATH);
	if (read_count == 0 || read_count == -1)
	{
		free(lineptr);
		return (-1);
	}
	strcpy(*lineptr, buff);
	return (read_count);
}
