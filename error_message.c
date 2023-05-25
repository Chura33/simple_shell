#include "phics.h"
/**
  *err_message - create a char * with err message
  *@av: caller
  *@args: argument 0
  *@err_mg: error message
  *
  *Return: the error char *
  */
void err_msg(char *av, char *args, char *err_mg)
{
	char err[1024];
	_strcpy(err, av);
	_strcat(err, ": 1: ");
	_strcat(err, args);
	strcpy(err_mg, err);
	return;
}
