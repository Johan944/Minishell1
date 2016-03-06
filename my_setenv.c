/*
** my_setenv.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 12:03:05 2016 johan ganem--brunet
** Last update Sun Jan 24 20:25:48 2016 johan ganem--brunet
*/

#include "minishell.h"

char	**add(char **env, char **args)
{
  char	**new_env;
  int	i;

  i = 0;
  if ((new_env = malloc(sizeof(char **) * (my_tablen(env) * 2))) == NULL)
    malloc_fail();
  while (env[i] != 0)
    {
      if ((new_env[i] = malloc(sizeof(char *) * (my_strlen(env[i]) * 2)))
	  == NULL)
	malloc_fail();
      new_env[i] = env[i];
      i += 1;
    }
  new_env[i] = get_file(args[1], "=");
  if (args[2] != NULL)
    new_env[i] = get_file(new_env[i], args[2]);
  return (new_env);
}

char	**edit(char **env, char **args, int i)
{
  t_var	var;

  var.j = 0;
  var.k = 0;
  var.str = env[i];
  var.len = my_strlen(var.str);
  if ((env[i] = malloc(sizeof(char *) * (var.len + my_strlen(args[1])) * 2))
      == NULL)
    malloc_fail();
  while (var.str[var.j - 1] != '=')
    {
      env[i][var.j] = var.str[var.j];
      var.j += 1;
    }
  while (args[2][var.k] != 0)
    {
      env[i][var.j] = args[2][var.k++];
      var.j += 1;
    }
  return (env);
}

char	**my_setenv(char **env, char **args)
{
  int	i;

  i = 0;
  if (args[1] == 0)
    {
      my_putstr_error("error: too few arguments\n");
      return (env);
    }
  if (args[1][0] <= 'A' || (args[1][0] >= 91 && args[1][0] <= 96)
      || args[1][0] >= 123)
    {
      my_putstr_error("setenv: Variable name must begin with a letter.\n");
      return (env);
    }
  while (env[i] != 0)
    {
      if (my_strncmp(env[i++], args[1], my_strlen(args[1])) == 0)
	return (edit(env, args, i - 1));
    }
  return (add(env, args));
}
