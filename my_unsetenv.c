/*
** my_unsetenv.c for $ in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 16:20:56 2016 johan ganem--brunet
** Last update Sun Jan 24 14:20:03 2016 johan ganem--brunet
*/

#include "minishell.h"

char	**delete(char **env, char *name, int i)
{
  if (env[i + 1] == 0)
    {
      env[i] = 0;
      return (env);
    }
  while (env[i + 1] != 0)
    {
      env[i] = env[i + 1];
      i += 1;
    }
  env[i] = 0;
  return (env);
}

char	**my_unsetenv(char **env, char *name)
{
  int	i;

  i = 0;
  if (name == 0)
    {
      my_putstr_error("unsetenv: Too few arguments.");
      return (env);
    }
  while (env[i] != 0)
    {
      if (my_strncmp(env[i], name, my_strlen(name)) == 0)
	return (delete(env, name, i));
      i += 1;
    }
  return (env);
}
