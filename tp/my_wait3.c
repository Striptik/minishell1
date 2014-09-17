/*
** my_wait3.c for troisieme op in /home/loisel_k/taff/C/Systeme-Unix/minishell1/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Dec 17 23:39:04 2013 Kevin LOISELEUR
** Last update Wed Dec 18 00:17:23 2013 Kevin LOISELEUR
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "include/my.h"
int		main(int ac, char **av)
{
  pid_t		pid;
  int		status;

  if ((pid = fork()) == -1)
    {
      my_printf("Erreur ta race de fork\n");
      exit(8);
    }
  else if (pid == 0)
    {
      my_printf("Je suis le processus fils trou de balle");
      sleep(3);
      exit(4);
    }
  else
    {
      my_printf("Je suis le pere et alors ???\n");
      wait(&status);
      if (!(WIFEXITED(status))) //si NULL : le fils ne s'est pas fini normal
	{
	  my_printf("Ca cest pas fini normalement mon gars");
	  exit(42);
	}
      if ((WTERMSIG(status)))
	my_printf("C'est le signal :%d qui a quitte le fils.\n", WTERMSIG(status));
    }
}
