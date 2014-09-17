/*
** minishell_zoo.c for Minishell test in /home/loisel_k/taff/C/Systeme-Unix/minishell1/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Dec 18 12:14:21 2013 Kevin LOISELEUR
** Last update Thu Feb 27 18:49:15 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/my.h"
#include "../include/list.h"
#include "mysh.h"

void		minishell(char **env)
{
  if (!env[0])
    minishell_main_env_null();
  else
    minishell_main(env);
  return ;
}

void		minishell_main(char **tab_env)
{
  char		*buf;
  char		**av;
  t_listp	*env;
  t_listp	*path;
  int		res;

  env = init_env(tab_env);
  path = init_path(env);
  signal(SIGINT, signal_handler);
  while (4)
    {
      my_printf("%s", PS1);
      if ((buf = get_next_line(0)))
	{
	  av = create_word_tab(buf);
	  if ((res = parse_my_read(av, path)) == -1)
	    return ;
	  exec_my_read(res, av, env, path);
	}
    }
  free_list(env, path);
  return ;
}

int		main(int ac, char **av, char **env)
{
  minishell(env);
  return (0);
}
