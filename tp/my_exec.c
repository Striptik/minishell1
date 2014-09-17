/*
** my_fork_exec.c for fork et execution in /home/loisel_k/taff/C/Systeme-Unix/minishell1/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Mon Dec 16 18:54:48 2013 Kevin LOISELEUR
** Last update Tue Dec 17 18:21:04 2013 Kevin LOISELEUR
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "include/my.h"

int		main(int ac, char **av)
{
pid_t		pid;

  pid = getpid();
  my_printf("Le PID A TA MERE :%d\n", pid);
  if (execl("/bin/ls", "/bin/ls", "-la", 0) == -1)
      my_printf("ca marche pas connard\n");
}
