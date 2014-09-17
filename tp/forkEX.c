/*
** fork.c for fork in /home/loisel_k/taff/C/Systeme-Unix/minishell1/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Thu Dec 12 09:52:23 2013 Kevin LOISELEUR
** Last update Thu Dec 12 11:00:55 2013 Kevin LOISELEUR
*/

#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    {
      fprintf(stderr, "[ERROR]: fork problem\n");
      return (1);
    }
  if (pid == 0)
    printf("Je suis le fils avec le pid numero %d\n", pid);
  else
    wait_pid(pid);
  return (0);
}

int		wait_pid(pid_t pid)
{
  int		status;

  printf("Je suis le pere, le pid de mon fils est: %d %d \n", pid, status);
  wait(&status);
  printf("Mon fils a termine de faire ce qu'il devait faire\nle status est : %d\n", status);
  return ;
}
