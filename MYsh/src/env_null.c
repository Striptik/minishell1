/*
** env_null.c for environnement null in /home/loisel_k/taff/C/Systeme-Unix/minishell1/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Sat Jan  4 19:44:05 2014 Kevin LOISELEUR
** Last update Wed Feb 19 13:24:13 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/list.h"
#include "mysh.h"

void		minishell_main_env_null(void)
{
  char		*buf;
  char		*error;

  while (42)
    {
      my_printf("%s", PS1);
      {
	if ((buf = get_next_line(0)))
	  {
	    if (my_strncmp(buf, "exit", 4) == 0)
	      return ;
	    put_error_env_null(buf, error);
	    my_rprintf("%s\n", error);
	  }
      }
    }
  return ;
}

void		put_error_env_null(char *buf, char *error)
{
  int		len;

  error = my_realloc(buf, ERROR_ENV_NULL);
  return ;
}
