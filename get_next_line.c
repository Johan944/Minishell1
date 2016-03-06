/*
** get_next_line.c for  in /home/ganem-_j/CPE_2015_getnextline
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sun Jan 17 13:06:33 2016 johan ganem--brunet
** Last update Sun Jan 24 18:37:38 2016 johan ganem--brunet
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*get_next_line(const int fd)
{
  static t_vars	var;

  if ((var.idx == 0 && (var.value_read = read(fd, var.buf, READ_SIZE)) < 1)
      || (var.idx_line == 0 && (var.line = malloc(SIZE_MALLOC)) == NULL))
    {
      my_putstr("exit\n");
      exit(1);
    }
  while (var.idx != var.value_read)
    {
      if (var.buf[var.idx] == '\n' || var.buf[var.idx] == 0)
	{
	  var.idx += 1;
	  var.line[var.idx_line] = 0;
	  var.idx_line = 0;
	  return (var.line);
	}
      var.line[var.idx_line] = var.buf[var.idx];
      var.idx_line += 1;
      var.idx += 1;
    }
  var.idx = 0;
  get_next_line(fd);
}
