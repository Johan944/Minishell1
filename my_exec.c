/*
** my_exec.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 11:29:17 2016 johan ganem--brunet
** Last update Sun Jan 24 20:42:49 2016 johan ganem--brunet
*/

#include "minishell.h"

int	command_not_found(char *str)
{
  my_putstr_error(str);
  my_putstr_error(" : command not found\n");
  return (1);
}

int	exec(t_var var, char **env)
{
  var.i = 0;
  var.k = 0;
  var.path_tab = str_do_wordtab(get_path(env, var));
  if (var.path_tab == NULL)
    return (command_not_found(var.args2[0]));
  if ((var.pid = fork()) == -1)
    fork_fail();
  while (var.path_tab[var.i] != 0)
    {
      if (var.pid == 0 && my_strncmp(var.args2[0], "./", 2) == 0)
	execve(var.args2[0], var.args2, env);
      else if  (var.pid == 0 && my_strncmp(var.args2[0], "/", 1) != 0)
	{
	  var.path = get_file(var.path_tab[var.i], var.args2[0]);
	  execve(var.path, var.args2, env);
	}
      else if (var.pid == 0)
	execve(var.args2[0], var.args2, env);
      else
	return (1);
      var.i += 1;
    }
  my_putstr_error(var.args2[0]);
  my_putstr_error(" : command not found\n");
  exit(0);
}
