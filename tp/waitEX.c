/*
** waitEX.c for wait cours in /home/loisel_k/taff/C/Systeme-Unix/minishell1/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Fri Dec 13 17:19:45 2013 Kevin LOISELEUR
** Last update Fri Dec 13 17:32:29 2013 Kevin LOISELEUR
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "include/my.h"

int		main(void)
{
  pid_t		pid;
  int		status;

  if ((pid = fork()) == -1)
    {
      my_printf("Erreur fork ma gueule\n");
      return (-1);
    }
  if (pid == 0)
    my_printf("Je suis le fils\n");
  else
    {
      my_printf("Je suis le pere, le pid de mon fils est : %d\n", pid);
      wait(&status);
      my_printf("Mon fils a termine ce qu'il a a faire, retour papa\n");
    }
}
