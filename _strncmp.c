#include "phics.h"
/**
* _strncmp - compares two strings
* @s1: first string
* @s2: second string
* @n: number of bytes to check
* Return: returns an integer
*/
int _strncmp(const char *s1, char *s2, size_t n)
{
	size_t i = 0;
	int flag = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		return (0);
	return (s1[i] - s2[i]);
}
