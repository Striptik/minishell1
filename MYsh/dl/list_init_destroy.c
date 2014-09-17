/*
** list_init.c for list initialisation in /home/loisel_k/taff/C/Systeme-Unix/minishell1/dl
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Dec 18 20:18:57 2013 Kevin LOISELEUR
** Last update Sun Jan  5 18:46:41 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "list.h"
#include "../include/my.h"

t_listp			*init_list(void)
{
  t_listp		*list;

  if (!(list = malloc(sizeof(*list))))
    {
      my_rprintf("Error on list init.\n");
      return (NULL);
    }
  list->beg = NULL;
  list->end = NULL;
  list->size = 0;
  return (list);
}

int			del_list(t_listp *list)
{
  while (list->size > 1)
    del_elem(list, 1);
  free(list->beg->data);
  free(list->beg);
  free(list);
  return (0);
}
