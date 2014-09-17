/*
** main.c for maintest in /home/loisel_k/taff/C/Systeme-Unix/minishell1
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Fri Dec 20 23:07:32 2013 Kevin LOISELEUR
** Last update Sat Jan  4 19:37:49 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "../include/list.h"

int		main(int ac, char **av, char **env)
{
  t_listp	*list;
  int		i;

  i = 0;
  list = init_list();
  while (env[i])
    {
      ins_elem(list, env[i], 1);
      i++;
    }
  rev_disp_list(list);
  del_list(list);
  return (0);
}
