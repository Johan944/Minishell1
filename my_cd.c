/*
** my_cd.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 10:33:21 2016 johan ganem--brunet
** Last update Sun Jan 24 21:09:08 2016 johan ganem--brunet
*/

#include "minishell.h"

int		my_cd(t_var var, char **env)
{
  char		*dest;
  char		**old;

  if ((old = malloc(3)) == NULL || (old[2] = malloc(1000)) == NULL)
    malloc_fail();
  old[0] = "setenv";
  old[1] = "OLDPWD";
  old[2] = getcwd(old[2], 1000);
  if (var.args2[1] == 0 || var.args2[1] == NULL
      || my_strcmp(var.args2[1], "~") == 0)
    dest = search(env, "HOME=");
  else if (my_strcmp(var.args2[1], "-") == 0)
    dest = search(env, "OLDPWD=");
  else
    dest = var.args2[1];
  if (chdir(dest) != -1)
    my_setenv(env, old);
  else if (access(dest, F_OK) == -1)
    {
      my_putstr_error(var.args2[1]);
      my_putstr_error(": No such file or directory.\n");
    }
  else if (access(dest, X_OK) == -1)
    my_putstr_error("Check the rights in the folder\n");
  return (0);
}
