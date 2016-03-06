/*
** error.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Tue Jan 19 11:11:14 2016 johan ganem--brunet
** Last update Sat Jan 23 11:39:26 2016 johan ganem--brunet
*/

#include <stdlib.h>

void	malloc_fail()
{
  my_putstr_error("Malloc failed\n");
  exit(-1);
}

void	fork_fail()
{
  my_putstr_error("Fork failed\n");
  exit(-1);
}
