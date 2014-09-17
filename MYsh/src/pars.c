/*
** pars.c for parsing for minishell in /home/loisel_k/taff/C/Systeme-Unix/minishell1/MYsh/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Mon Jan  6 22:47:30 2014 Kevin LOISELEUR
** Last update Thu Jan  9 11:21:23 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/list.h"
#include "mysh.h"


int		parse_my_read(char **av, t_listp *path)
{
  if (!(my_strcmp(av[0], "exit")))
    return (-1);
  if (is_builtin(av))
    return (1);
  else if (is_cmd(av, path))
    return (0);
  else
    return (2);
}

int		is_builtin(char **av)
{
  char		**builtins;
  int		res;
  int		i;

  i = 0;
  builtins = malloc(sizeof(char *) * 5);
  builtins[0] = "env";
  builtins[1] = "setenv";
  builtins[2] = "unsetenv";
  builtins[3] = "cd";
  builtins[4] = NULL;
  while (builtins[i] != NULL)
    {
      if (!(my_strcmp(builtins[i], av[0])))
	return (1);
      i++;
    }
  return (0);
}

int		is_cmd(char **av, t_listp *path)
{
  t_list	*bin;
  char		*tmp;
  char		*tmp2;

  bin = path->beg;
  while (bin->next)
    {
      tmp = my_strcat(bin->data, "/");
      tmp2 = my_strcat(tmp, av[0]);
      if (access(tmp2, X_OK) != -1)
	{
	  free(tmp);
	  free(tmp2);
	  return (1);
	}
      else
	{
	  bin = bin->next;
	  free(tmp);
	  free(tmp2);
	}
    }
  return (0);
}
