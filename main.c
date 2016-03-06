/*
** main.c for  in /home/ganem-_j/rendu/PSU_2015_minishell1
**
** Made by johan ganem--brunet
** Login   <ganem-_j@epitech.net>
**
** Started on  Thu Jan 21 11:28:41 2016 johan ganem--brunet
** Last update Sun Jan 24 21:01:08 2016 johan ganem--brunet
*/

#include "minishell.h"
#include "get_next_line.h"

void	my_signal(int signal)
{
  t_var	var;

  if (signal == SIGINT)
    {
      my_putchar('\n');
      my_putstr(get_prompt(var));
    }
}

int	detect_signal_child(pid_t pid)
{
  if (WIFSIGNALED(pid))
    {
      if (WTERMSIG(pid) == SIGSEGV)
	my_putstr_error("Segmentation fault\n");
      else
	my_putstr_error("Stopped\n");
      return (1);
    }
  return (0);
}

int	main(int ac, char **av, char **env)
{
  t_var	var;

  if (env[0] == NULL)
    if ((env = malloc(sizeof(char **) * (1000))) == NULL)
      malloc_fail();
  var.prompt = get_prompt(var);
  my_putstr(var.prompt);
  signal(SIGINT, my_signal);
  signal(SIGQUIT, my_signal);
  signal(SIGTSTP, my_signal);
  while (1)
    {
      var.i = 0;
      var.args2 = str_do_wordtab(get_next_line(0));
      if (var.args2[0] == 0);
      else if (detect_builtins(var) == 1)
	env = builtins(env, var);
      else
	var.pid = exec(var, env);
      wait(&var.pid);
      detect_signal_child(var.pid);
      my_putstr((var.prompt = get_prompt(var)));
    }
}
