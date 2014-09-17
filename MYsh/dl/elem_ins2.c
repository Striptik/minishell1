/*
** elem_ins2.c for insert elem in list 2 in /home/loisel_k/taff/C/Systeme-Unix/minishell1/dl
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Fri Dec 20 22:17:46 2013 Kevin LOISELEUR
** Last update Mon Dec 23 17:16:33 2013 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "list.h"
#include "../include/my.h"

int			ins_before_elem(t_listp *list, char *data, int pos)
{
  int			i;
  t_list		*elem;
  t_list		*current;

  i = 1;
  if (!(elem = malloc(sizeof(*elem))))
    return (-1);
  if (!(elem->data = my_strdup(data)))
    return (-1);
  current = list->beg;
  while (i < pos)
    {
      current = current->next;
      i++;
    }
  elem->next = current;
  elem->prev = current->prev;
  if (!current->prev)
    list->beg = elem;
  else
    current->prev->next = elem;
  current->prev = elem;
  list->size++;
  return (0);
}

int			ins_after_elem(t_listp *list, char *data, int pos)
{
  int			i;
  t_list		*elem;
  t_list		*current;

  i = 1;
  if (!(elem = malloc(sizeof(*elem))))
    return (-1);
  if (!(elem->data = my_strdup(data)))
    return (-1);
  current = list->beg;
  while (i < pos)
    {
      current = current->next;
      i++;
    }
  elem->next = current->next;
  elem->prev = current;
  if (!current->next)
    list->end = elem;
  else
    current->next->prev = elem;
  current->next = elem;
  list->size++;
  return (0);
}
