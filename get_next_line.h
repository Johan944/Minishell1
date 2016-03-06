/*
** get_next_line.h for  in /home/ganem-_j/CPE_2015_getnextline
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sun Jan 17 13:09:04 2016 johan ganem--brunet
** Last update Thu Jan 21 13:24:20 2016 johan ganem--brunet
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

#define		READ_SIZE (1)
#define		SIZE_MALLOC (4096)

typedef struct	s_vars
{
  int		idx;
  int		idx_line;
  int		k;
  int		value_read;
  char		buf[READ_SIZE];
  char		*line;
}		t_vars;

char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
