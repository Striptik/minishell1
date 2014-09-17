/*
** list_display.c for display list in /home/loisel_k/taff/C/Systeme-Unix/minishell1/dl
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Fri Dec 20 22:22:54 2013 Kevin LOISELEUR
** Last update Mon Dec 23 18:19:08 2013 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "list.h"
#include "../include/my.h"

void			disp_list(t_listp *list)
{
  t_list		*current;
  int			i;

  i = 0;
  current = list->beg;
  while (i < list->size)
    {
      my_printf("%s\n", current->data);
      current = current->next;
      i++;
    }
  return ;
}

void			rev_disp_list(t_listp *list)
{
  t_list		*current;
  int			i;

  i = 0;
  current = list->end;
  while (current)
    {
      my_printf("%s\n", (char *)current->data);
      current = current->prev;
    }
  return ;
}
