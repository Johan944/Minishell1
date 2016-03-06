/*
** functions_error.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 11:05:21 2016 johan ganem--brunet
** Last update Sat Jan 23 11:56:51 2016 johan ganem--brunet
*/

#include <stdlib.h>

void	my_putchar_error(char c)
{
  write(2, &c, 1);
}

void	my_putstr_error(char *str)
{
  int	i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != 0)
	{
	  my_putchar_error(str[i]);
	  i += 1;
	}
    }
}
