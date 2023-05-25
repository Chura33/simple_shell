#include "phics.h"
/**
 * _strcpy - copy a string
 * @s1: destination
 * @s2: source
 *
 * Return: s1
 */
char *_strcpy(char *s1, char *s2)
{
	int i;

	for (i = 0; s2[i] != '\0'; i++)
	{
		s1[i] = s2[i];
	}
	s1[i] = '\0';
	return (s1);
}
