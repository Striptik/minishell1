/*
** list_tools.c for tools for list in /home/loisel_k/taff/C/Systeme-Unix/minishell1/dl
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Fri Dec 20 22:20:15 2013 Kevin LOISELEUR
** Last update Sun Jan  5 22:21:54 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "list.h"
#include "../include/my.h"

t_listp			*search_elem(t_listp *list, char *data)
{
  t_listp		*new_list;
  t_list		*current;
  int			yess;

  yess = 0;
  if (!list->size || !list)
    return (NULL);
  current = list->beg;
  yess = 0;
  while (!yess && current)
    {
      if (current->data == data)
	{
	  new_list = init_list();
	  if ((ins_elem(new_list, current->data, 1)) == -1)
	    return (NULL);
	  yess = 1;
	}
      else
	current = current->next;
    }
  return (new_list);
}

t_listp			*search_lchar_elem(t_listp *list, char *data, int len)
{
  t_listp		*new_list;
  t_list		*current;
  int			yess;

  yess = 0;
  if (!list->size || !list)
    return (NULL);
  current = list->beg;
  yess = 0;
  while (!yess && current)
    {
      if (my_strncmp(current->data, data, len) == 0)
	{
	  new_list = init_list();
	  if ((ins_elem(new_list, current->data, 1)) == -1)
	    return (NULL);
	  yess = 1;
	}
      else
	current = current->next;
    }
  return (new_list);
}

int			position_elem(t_listp *list, char *data)
{
  t_list		*current;
  int			pos;

  pos = 0;
  if (!list || !list->size)
    {
      my_rprintf("List is empty !\n");
      return (-1);
    }
  current = list->beg;
  while (current)
    {
      pos++;
      if (current->data == data)
	return (pos);
      else
	current = current->next;
    }
  return (-1);
}

int			position_lchar_elem(t_listp *list, char *data, int len)
{
  t_list		*current;
  int			pos;

  pos = 0;
  if (!list || !list->size)
    {
      my_rprintf("List is empty\n");
      return (-1);
    }
  current = list->beg;
  while (current)
    {
      pos++;
      if (my_strncmp(current->data, data, len) == 0)
	return (pos);
      else
	current = current->next;
    }
  return (-1);
}

t_listp			*reverse_list(t_listp *list)
{
  t_listp		*new_list;
  t_list		*current;
  int			pos;

  pos = 1;
  if (!list)
    {
      my_rprintf("list is empty !\n");
      return (NULL);
    }
  current = list->end;
  new_list = init_list();
  while (current)
    {
      ins_elem(new_list, current->data, pos);
      current = current->prev;
      pos++;
    }
  return (new_list);
}
