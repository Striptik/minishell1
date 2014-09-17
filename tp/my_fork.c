/*
** my_fork.c for my_fork in /home/loisel_k/taff/C/Systeme-Unix/minishell1/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Fri Dec 13 14:02:48 2013 Kevin LOISELEUR
** Last update Tue Dec 17 17:27:01 2013 Kevin LOISELEUR
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "include/my.h"

/*
** fork : 
** pidP = ppidF
** signal de terminaison du fils est SIGCHLD
** apres le fork on est dans le process F
**
**
*/

int		my_fork(void)
{
  pid_t		pid;
  pid_t		sid;
  pid_t		gid;
  pid_t		ppid;

  pid = fork();
  if (pid == -1)
    {
      my_printf("Error fork.\n");
      exit(3);
    }
  else if (pid == 0)
    {
      ppid = getppid();
      sid = getsid(pid);
      gid = getpgid(pid);
      my_printf("PID fils : %d, PPID : %d, SID : %d, GID : %d\n", pid, ppid, sid, gid);
    }
  else if (pid > 0)
    {
      sid = getsid(pid);
      gid = getpgid(pid);
      my_printf("\n\nPID pere : %d, SID: %d, GID : %d\n", pid, sid, gid);
    }
  while (42);
  return (0);
}

int		main(void)
{
  my_printf("%d", my_fork());
}
