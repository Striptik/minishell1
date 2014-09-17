/*
** exec.c for exec for minishell1 in /home/loisel_k/taff/C/Systeme-Unix/minishell1/MYsh/src
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Mon Jan  6 22:44:14 2014 Kevin LOISELEUR
** Last update Mon Jan  6 22:47:01 2014 Kevin LOISELEUR
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "../include/my.h"
#include "../include/list.h"
#include "mysh.h"

void		exec_my_read(int res, char **av, t_listp *env, t_listp *path)
{
  pid_t		pid;
  int		status;

  if (res == 2)
    {
      my_rprintf("mysh: %s: command not found.\n", av[0]);
      return ;
    }
  if (pid = fork() == -1)
    {
      my_rprintf("Error on Forking processus.\n");
      return ;
    }
  else if (pid == 0)
    {
      if (res == 0)
	exec_cmd(av, env, path);
      else if (res == 1)
	exec_builtin(av, env, path);
      exit(3);
    }
  else
    waitpid(pid, 0, 0);
  return ;
}

void		exec_builtin(char **av, t_listp *env, t_listp *path)
{
  /* if  (my_strcmp(av[0], "env") == 0)
   my_env(av, env);
 else if (my_strcmp(av[0], "setenv") == 0)
   my_setenv(av, env);
 else if (my_strcmp(av[0], "unsetenv") == 0)
   my_unsetenv(av, env);
 else if (my_strcmp(av[0], "cd") == 0)
   my_cd(av, env);
 else
   my_rprintf("mysh: %s: Built-In Not find.\n", av[0]);
   return ;*/
}

void		exec_cmd(char **av, t_listp *env, t_listp *path)
{
  t_list	*bin;
  char		*tmp;
  char		*tmp2;

  bin = path->beg;
  while (bin->next)
    {
      tmp = my_strcat(bin->data, "/");
      tmp2 = my_strcat(tmp, av[0]);
      if (execve(tmp2, av, env_tab(env)) != -1)
	{
	  free(tmp);
	  free(tmp2);
	  return ;
	}
      else
	bin = bin->next;
      free(tmp);
      free(tmp2);
    }
  my_rprintf("mysh: %s: Command Not find.\n", av[0]);
  return ;
}
