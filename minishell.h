/*
** minishell.h for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Mon Jan 18 21:40:54 2016 johan ganem--brunet
** Last update Sun Jan 24 20:51:24 2016 johan ganem--brunet
*/

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef		MINISHELL_H_
# define	MINISHELL_H_

#define		PATH_DEFAUT	"PATH="

typedef struct	s_var
{
  char		**tab;
  char		**args2;
  char		**path_tab;
  char		**new_env;
  char		*args1;
  char		*path;
  char		*prompt;
  char		*buf;
  char		*home;
  char		*name;
  char		*value;
  char		*str;
  int		i;
  int		j;
  int		k;
  int		idx;
  int		len;
  int		overwrite;
  pid_t		pid;
}		t_var;

char	**delete(char **env, char *name, int i);
char	**my_unsetenv(char **env, char *name);
char	**add(char **env, char **args);
char	**builtins(char **env, t_var var);
char	**my_setenv(char **env, char **args);
char	**edit(char **env, char **args, int i);
char	**str_do_wordtab(char *str);
char	*get_home(char **env);
char	*get_path(char **str, t_var var);
char	*get_file(char *path, char *args);
char	*get_prompt(t_var var);
char	*get_value(char *str);
char	*search(char **env, char *str);
int	check_chdir(t_var var, char ** env);
int	detect_builtins(t_var var);
int	exec(t_var var, char **env);
int	main(int ac, char **av, char **env);
int	my_cd(t_var var, char **env);
int	my_strncmp(char *s1, char *s2, int n);
int	my_tablen(char **tab);
int	my_atoi(char *str);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
void	fork_fail();
void	malloc_fail();
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_putchar_error(char c);
void	my_putstr_error(char *str);

#endif /* !MINISHELL_H_ */
