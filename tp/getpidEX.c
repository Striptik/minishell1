/*
** getpid.c for getpid in /home/loisel_k/taff/C/Systeme-Unix/minishell1/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Thu Dec 12 09:48:24 2013 Kevin LOISELEUR
** Last update Thu Dec 12 09:51:13 2013 Kevin LOISELEUR
*/

#include <unistd.h>
#include <stdio.h>

int		main(int ac, char **av)
{
  pid_t		pid;
  pid_t		ppid;

  pid = getpid();
  ppid = getppid();
  printf("Mon PID est %d, celui de papa %d.\n", pid, ppid);
  return (0);
}
