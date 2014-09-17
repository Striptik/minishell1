/*
** builtin1.c for builtin for minishell in /home/loisel_k/taff/C/Systeme-Unix/minishell1/MYsh/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Sun Jan  5 22:47:54 2014 Kevin LOISELEUR
** Last update Wed Feb 19 13:21:55 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/list.h"
#include "mysh.h"

int		my_env(char **av, t_listp *env)
{
  disp_list(env);
  return (1);
}

int		my_setenv(char **av, t_listp *env)
{
  char		*tmp;
  char		*tmp2;

  if (av[1] == NULL)
    {
      disp_list(env);
      return (1);
    }
  else
    {
      tmp = my_strcat(av[1], "=");
      tmp2 = my_strcat(tmp, av[2]);
      free (tmp);
      ins_elem(env, tmp2, env->size);
    }
  return (2);
}

int		my_unsetenv(char **av, t_listp *env)
{
  int		len;
  int		pos;

  if (av[1] != NULL)
    {
      len = my_strlen(av[1]);
      if ((pos = position_lchar_elem(env, av[1], len)) == -1)
	{
	  my_rprintf("Variable Not found.\n");
	  return (-1);
	}
      del_elem(env, pos);
    }
  return (1);
}
