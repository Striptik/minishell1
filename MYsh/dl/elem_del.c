/*
** elem_del.c<2> for delete elem in list in /home/loisel_k/taff/C/Systeme-Unix/minishell1/dl
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Fri Dec 20 22:18:51 2013 Kevin LOISELEUR
** Last update Mon Dec 23 18:22:29 2013 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "list.h"
#include "../include/my.h"

int			del_elem(t_listp *list, int pos)
{
  if (!list || !list->size)
    {
      my_rprintf("List is empty MOFCK !\n");
      return (-1);
    }
  if (pos < 0 || pos > list->size)
    {
      my_rprintf("Bad position !\n");
      return (-1);
    }
  else if (pos == 1)
    del_elem_beg_list(list);
  else if (pos == list->size)
    del_elem_end_list(list);
  else
    del_x_elem(list, pos);
  return (0);
}

int			del_elem_beg_list(t_listp *list)
{
  t_list		*elem;

  elem = list->beg;
  list->beg = list->beg->next;
  if (!list->beg->prev)
    list->end = NULL;
  else
    list->beg->prev = NULL;
  list->size--;
  free(elem->data);
  free(elem);
  return (0);
}

int			del_elem_end_list(t_listp *list)
{
  t_list		*elem;

  elem = list->end;
  list->end = list->end->prev;
  list->end->prev->next = NULL;
  list->size--;
  free(elem->data);
  free(elem);
  return (0);
}

int			del_x_elem(t_listp *list, int pos)
{
  int			i;
  t_list		*elem;
  t_list		*current;

  i = 1;
  current = list->beg;
  while (i < pos)
    {
      current = current->next;
      i++;
    }
  elem = current;
  current->prev->next = current->next;
  current->next->prev = current->prev;
  list->size--;
  free(elem->data);
  free(elem);
  return (0);
}
