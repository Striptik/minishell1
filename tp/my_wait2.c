/*
** my_wait2.c for my_wait2 in /home/loisel_k/taff/C/Systeme-Unix/minishell1/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Dec 17 19:09:24 2013 Kevin LOISELEUR
** Last update Tue Dec 17 23:36:10 2013 Kevin LOISELEUR
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

int		main(int ac, char **av)
{
  pid_t		pid;
  int		status;

  pid = fork();
  if (pid > 0)
    {
      wait(&status);
      WIF
      my_printf("%d\n", status);
      sleep(2);
      my_printf("aller je vais me coucher\n");
    }
  else if (pid == 0)
    {
      my_printf("Je suis le fils\n");
      sleep(2);
      exit(1);
    }
  return (0);
}
