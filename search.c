/*
** search.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Sat Jan 23 10:34:56 2016 johan ganem--brunet
** Last update Sun Jan 24 21:06:34 2016 johan ganem--brunet
*/

#include <stdlib.h>

char	*get_value(char *str)
{
  int	i;
  int	j;
  char	*result;

  i = 0;
  j = 0;
  if ((result = malloc(sizeof(char *) * (my_strlen(str)))) == NULL)
    malloc_fail();
  while (str[i - 1] != '=')
    i += 1;
  while (str[i] != 0)
    result[j++] = str[i++];
  return (result);
}

char	*search(char **env, char *str)
{
  int	i;
  int	len;

  i = 0;
  if ((len = my_strlen(str)) == 0)
    return (NULL);
  if (env[0] == NULL)
    return (NULL);
  while (env[i] != 0)
    {
      if (my_strncmp(env[i], str, len) == 0)
	return (get_value(env[i]));
      i += 1;
    }
  return (NULL);
}
