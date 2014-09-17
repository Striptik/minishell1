/*
** elem_ins.c for insert elem in list in /home/loisel_k/taff/C/Systeme-Unix/minishell1/dl
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Fri Dec 20 22:15:55 2013 Kevin LOISELEUR
** Last update Sun Dec 29 02:08:00 2013 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "list.h"
#include "../include/my.h"

int			ins_elem(t_listp *list, char *data, int pos)
{
  t_list		*elem;

  if (list == NULL)
    {
      my_rprintf("List does not exist. init it !\n");
      return (-1);
    }
  if (list->size == 0)
    ins_elem_empty_list(list, data);
  else if (pos > list->size || pos < 0)
    {
      my_rprintf("Bad position !\n");
      return (-1);
    }
  else if (pos == 1)
    ins_elem_beg_list(list, data);
  else if (pos == list->size)
    ins_elem_end_list(list, data);
  else
    ins_after_elem(list, data, pos);
  return (0);
}

int			ins_elem_empty_list(t_listp *list, char *data)
{
  t_list		*elem;

  if (!(elem = malloc(sizeof(*elem))))
    {
      my_rprintf("My malloc has shit !\n");
      return (-1);
    }
  if (!(elem->data = my_strdup(data)))
    {
      my_rprintf("My duplication has shit !\n");
      return (-1);
    }
  elem->next = list->beg;
  elem->prev = list->end;
  list->beg = elem;
  list->end = elem;
  list->size++;
  return (0);
}

int			ins_elem_beg_list(t_listp *list, char *data)
{
  t_list		*elem;\

  if (!(elem = malloc(sizeof(*elem))))
    {
      my_rprintf("My malloc has shit\n");
      return (-1);
    }
  if (!(elem->data = my_strdup(data)))
    {
      my_rprintf("My duplication has shit !\n");
      return (-1);
    }
  elem->next = list->beg;
  elem->prev = NULL;
  list->beg->prev = elem;
  list->beg = elem;
  list->size++;
  return (0);
}

int			ins_elem_end_list(t_listp *list, char *data)
{
  t_list		*elem;

  if (!(elem = malloc(sizeof(*elem))))
    {
      my_rprintf("My malloc has shit\n");
      return (-1);
    }
  if (!(elem->data = my_strdup(data)))
    {
      my_rprintf("My duplication has shit !\n");
      return (-1);
    }
  elem->next = NULL;
  elem->prev = list->end;
  list->end->next = elem;
  list->end = elem;
  list->size++;
  return (0);
}
