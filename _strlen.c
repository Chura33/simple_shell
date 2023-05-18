#include "phics.h"
/**
* _strlen - finds the length of a string
* @s: the string
* Return: returns a type of size_t
*/
size_t _strlen(const char *s)
{
	size_t i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
