/*
** get_prompt.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 11:26:32 2016 johan ganem--brunet
** Last update Sat Jan 23 11:30:40 2016 johan ganem--brunet
*/

#include "minishell.h"

char	*get_prompt(t_var var)
{
  var.i = 0;
  if ((var.buf = malloc(sizeof(char *) * 4096)) == NULL)
    malloc_fail();
  if ((var.buf = getcwd(var.buf, 4096)) == NULL);
  while (var.buf[var.i++] != 0);
  var.buf[--var.i] = '>';
  var.buf[++var.i] = ' ';
  return (var.buf);
}
