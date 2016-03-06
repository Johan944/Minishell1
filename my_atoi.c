/*
** my_atoi.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 01:07:23 2016 johan ganem--brunet
** Last update Sun Jan 24 13:02:15 2016 johan ganem--brunet
*/

int	my_atoi(char *str)
{
  int	i;
  int	j;
  int	idx;

  i = 0;
  j = 0;
  idx = 0;
  if (str[0] == '-')
    {
      idx = 1;
      i = 1;
    }
  while (str[i] != 0)
    {
      if (str[i] >= '0' && str[i] <= '9')
	{
	  j = j * 10;
	  j = j + str[i] - '0';
	}
      i = i + 1;
    }
  if (idx == 1)
    j = -j;
  return (j);
}
