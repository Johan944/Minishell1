/*
** builtins.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 16:53:52 2016 johan ganem--brunet
** Last update Sun Jan 24 12:44:29 2016 johan ganem--brunet
*/

#include "minishell.h"

char	**builtins(char **env, t_var var)
{
  if (my_strcmp(var.args2[0], "cd") == 0)
    my_cd(var, env);
  else if (my_strcmp(var.args2[0], "exit") == 0)
    my_exit(var.args2[1]);
  else if (my_strcmp(var.args2[0], "unsetenv") == 0)
    return (my_unsetenv(env, var.args2[1]));
  else if (my_strcmp(var.args2[0], "setenv") == 0)
    return (my_setenv(env, var.args2));
  else if (my_strcmp(var.args2[0], "env") == 0)
    disp_env(env);
  return (env);
}

int	detect_builtins(t_var var)
{
  if (my_strcmp(var.args2[0], "cd") == 0 ||
      my_strcmp(var.args2[0], "exit") == 0 ||
      my_strcmp(var.args2[0], "unsetenv") == 0 ||
      my_strcmp(var.args2[0], "setenv") == 0 ||
      my_strcmp(var.args2[0], "env") == 0)
    return (1);
  return (0);

}
