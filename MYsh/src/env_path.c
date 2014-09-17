/*
** env.c for init_env in /home/loisel_k/taff/C/Systeme-Unix/minishell1/MYsh/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Sun Jan  5 17:26:24 2014 Kevin LOISELEUR
** Last update Wed Feb 19 13:47:21 2014 Kevin LOISELEUR
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/list.h"
#include "mysh.h"

t_listp			*init_env(char **tab)
{
  int			i;
  t_listp		*env;

  i = 0;
  env = init_list();
  if (ins_elem(env, tab[i++], 1) == -1)
    {
      my_rprintf("Error to take the envirronement");
      return (NULL);
    }
  while (tab[i])
    {
      if (ins_elem(env, tab[i++], env->size) == -1)
	{
	  my_rprintf("Error to take the envirronement");
	  return (NULL);
	}
    }
  ins_elem(env, tab[i], env->size);
  return (env);
}

t_listp			*init_path(t_listp *env)
{
  int			i;
  int			j;
  t_listp		*path;
  t_listp		*tmp;

  i = 0;
  j = 0;
  tmp = search_lchar_elem(env, "PATH=", 5);
  while (tmp->beg->data && tmp->beg->data[i - 1] != '=')
    i++;
  while (tmp->beg->data && tmp->beg->data[i])
    tmp->beg->data[j++] = tmp->beg->data[i++];
  tmp->beg->data[j++] = 0;
  tmp->beg->data[j] = 0;
  path = cut_the_path(tmp->beg->data);
  del_list(tmp);
  return (path);
}

t_listp			*cut_the_path(char *str)
{
  int			i;
  int			j;
  char			*tmp;
  t_listp		*path;

  i = 0;
  path = init_list();
  while (str && str[i])
    {
      j = 0;
      tmp = NULL;
      if (!(tmp = malloc(sizeof(char) * count_char_before(str, i))))
	my_rprintf("Bad Malloc for the path.\n");
      while (str[i] != '\0' && str[i] != ':')
	tmp[j++] = str[i++];
      tmp[j] = 0;
      if (ins_elem(path, tmp, 1) == -1)
	my_rprintf("Bad insertion in list for the path.\n");
      i++;
      free(tmp);
    }
  ins_elem(path, NULL, path->size);
  return (path);
}

int			count_char_before(char *str, int i)
{
  int			count;

  count = 0;
  while (str && str[i] && str[i] != ':')
    {
      count++;
      i++;
    }
  return (count + 1);
}

char		**env_tab(t_listp *env)
{
  t_list	*str;
  char		**tab_env;
  int		i;

  i = 0;
  str = env->beg;
  if (!(tab_env = malloc(sizeof(char *) * (env->size + 1))))
    {
      my_rprintf("Failed to Malloc env's tab.\n");
      return (NULL);
    }
  while (str->next)
    {
      tab_env[i++] = str->data;
      str = str->next;
    }
  tab_env[i] = NULL;
  return (tab_env);
}
