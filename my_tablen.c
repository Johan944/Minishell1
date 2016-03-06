/*
** my_tablen.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 01:11:47 2016 johan ganem--brunet
** Last update Sat Jan 23 01:12:32 2016 johan ganem--brunet
*/

int	my_tablen(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != 0)
    i += 1;
  return (i);
}
