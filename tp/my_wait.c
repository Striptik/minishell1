/*
** my_wait.c for my_wait in /home/loisel_k/taff/C/Systeme-Unix/minishell1/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Dec 17 18:49:58 2013 Kevin LOISELEUR
** Last update Tue Dec 17 19:07:27 2013 Kevin LOISELEUR
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

int		main(void)
{
  pid_t		pid;
  pid_t		pid2;
  int		status;

  pid = fork();
  if (pid == -1)
    my_printf("Ton fork marche pas connard\n");
  else if (pid > 0)
    {
      wait(&status);
      sleep(2);
      my_printf("NON !!\n");
      sleep(5);
    }
  else if (pid == 0)
    {
      sleep(5);
      my_printf("Je suis ton fils\n");
      pid2 = fork();
      if (pid2 == 0)
	{
	  my_printf("Je suis le petit fils\n");
	  sleep(1);
	  exit(1);
	}
      else
	{
	  wait(&status);
	  sleep(1);
	  my_printf("Je suis toujours le fils\n");
	}
      exit(1);
    }
  return ;
}
