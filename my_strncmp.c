/*
** my_strncmp.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 10:40:26 2016 johan ganem--brunet
** Last update Sat Jan 23 10:58:21 2016 johan ganem--brunet
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (i < n && (s1[i] != 0 || s2[i] != 0))
    {
      if (s1[i] != s2[i])
	return (1);
      i += 1;
    }
  if (i == n)
    return (0);
  return (1);
}
