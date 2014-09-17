/*
** my_exec2.c for my_exec2.c in /home/loisel_k/taff/C/Systeme-Unix/minishell1/tp
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Tue Dec 17 17:33:08 2013 Kevin LOISELEUR
** Last update Tue Dec 17 17:46:11 2013 Kevin LOISELEUR
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int		main(int ac, char **av)
{
pid_t		pid;

  pid = getpid();
  my_printf("Mon PID est %d\n", pid);
  while (1);
}
