/*
** main.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sun Jan 17 17:08:24 2016 johan ganem--brunet
** Last update Sun Jan 24 18:38:45 2016 johan ganem--brunet
*/

#include "minishell.h"

char	*get_path(char **env, t_var var)
{
  while (env[var.i] != 0)
    {
      if (my_strncmp(env[var.i], "PATH=", 5) == 0)
	{
	  var.j = 5;
	  if ((var.path = malloc(sizeof(char *)*(my_strlen(env[var.i]) * 2)))
	      == NULL)
	    malloc_fail();
	  while (env[var.i][var.j] != 0)
	    {
	      var.path[var.k] = env[var.i][var.j++];
	      if (var.path[var.k]  == ':')
		{
		  var.path[var.k++] = '/';
		  var.path[var.k] = ' ';
		}
	      var.k += 1;
	    }
	  var.path[var.k++] = '/';
	  var.path[var.k] = 0;
	  return (var.path);
	}
      var.i += 1;
    }
  return (NULL);
}

char	*get_file(char *path, char *args)
{
  t_var	var;

  var.i = 0;
  var.j = 0;
  while (path[var.i] != 0)
    var.i += 1;
  while (args[var.j] != 0)
    {
      path[var.i] = args[var.j];
      var.i += 1;
      var.j += 1;
    }
  path[var.i] = 0;
  return (path);
}
