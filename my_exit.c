/*
** my_exit.c for  in /home/ganem-_j/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sun Jan 24 20:43:23 2016 johan ganem--brunet
** Last update Sun Jan 24 20:44:26 2016 johan ganem--brunet
*/

#include <stdlib.h>

void	my_exit(char *str)
{
  my_putstr_error("exit\n");
  if (str != NULL)
    exit(my_atoi(str));
  else
    exit(0);
}
