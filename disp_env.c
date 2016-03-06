/*
** disp_env.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 13:18:31 2016 johan ganem--brunet
** Last update Sun Jan 24 21:03:11 2016 johan ganem--brunet
*/

#include <stdlib.h>

int	disp_env(char **env)
{
  int	i;

  i = 0;
  if (env == NULL)
    {
      my_putstr_error("The env is empty\n");
      return (0);
    }
  while (env[i] != 0)
    {
      my_putstr(env[i++]);
      my_putchar('\n');
    }
}
