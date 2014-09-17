/*
** tools.c for tools.c in /home/loisel_k/taff/C/Systeme-Unix/minishell1/MYsh/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Mon Jan  6 22:50:39 2014 Kevin LOISELEUR
** Last update Mon Jan  6 22:54:04 2014 Kevin LOISELEUR
*/

#include <signal.h>
#include "../include/my.h"
#include "../include/list.h"
#include "mysh.h"

void		signal_handler(int sig)
{
  if (signal(sig, signal_handler) == SIG_ERR)
    my_rprintf("mysh : error : bad signal.\n");
  my_printf("%s", PS1);
  return ;
}

void			free_list(t_listp *env, t_listp *path)
{
  del_list(env);
  del_list(path);
  return ;
}
