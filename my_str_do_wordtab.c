/*
** my_str_do_wordtab.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 11:25:34 2016 johan ganem--brunet
** Last update Sun Jan 24 18:31:26 2016 johan ganem--brunet
*/

#include "minishell.h"

t_var	init()
{
  t_var	var;

  var.i = 0;
  var.j = 0;
  return (var);
}

char	**str_do_wordtab(char *str)
{
  t_var	var;

  if (str == NULL)
    return (NULL);
  var = init();
  if ((var.tab = malloc(sizeof(char **) * my_strlen(str) * 2)) == NULL)
    malloc_fail();
  while (var.i != my_strlen(str))
    if ((var.tab[var.i++] = malloc(sizeof(char *) * my_strlen(str) * 2))
	== NULL)
      malloc_fail();
  var.i = 0;
  while (str[var.i] != 0)
    {
      var.k = 0;
      while ((str[var.i] == '	' || str[var.i] == ' ') && str[var.i] != 0)
	var.i += 1;
      while (str[var.i] != '	' && str[var.i] != ' ' && str[var.i] != 0)
	var.tab[var.j][var.k++] = str[var.i++];
      while ((str[var.i] == '	' || str[var.i] == ' ') && str[var.i] != 0)
	var.i += 1;
      var.j += 1;
    }
  var.tab[var.j] = 0;
  return (var.tab);
}
