/*
** list.h for list in /home/loisel_k/taff/C/Systeme-Unix/minishell1/dl
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Dec 18 20:21:03 2013 Kevin LOISELEUR
** Last update Sun Jan  5 22:34:36 2014 Kevin LOISELEUR
*/

#ifndef _LIST_H_
# define _LIST_H_

typedef struct		s_list
{
  char			*data;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

typedef struct		s_listp
{
  t_list		*beg;
  t_list		*end;
  int			size;
}			t_listp;

/*
** Initialisation
*/

t_listp			*init_list(void);

/*
**  Insertion element
*/

int			ins_elem(t_listp *list, char *data, int pos);
int			ins_elem_empty_list(t_listp *list, char *data);
int			ins_elem_end_list(t_listp *list, char *data);
int			ins_elem_beg_list(t_listp *list, char *data);
int			ins_before_elem(t_listp *list, char *data, int pos);
int			ins_after_elem(t_listp *list, char *data, int pos);

/*
** deletion element
*/

int			del_elem(t_listp *list, int pos);
int			del_elem_beg_list(t_listp *list);
int			del_elem_end_list(t_listp *list);
int			del_x_elem(t_listp *list, int pos);

/*
** Tools
*/

int			position_elem(t_listp *list, char *data);
int			position_lchar_elem(t_listp *list, char *data, int len);
t_listp			*search_elem(t_listp *list, char *data);
t_listp			*search_lchar_elem(t_listp *list, char *data, int len);
t_listp			*reverse_list(t_listp *list);


/*
** Display
*/

void			disp_list(t_listp *list);
void			rev_disp_list(t_listp *list);

/*
** Destroy ...
*/

int			del_list(t_listp *list);

#endif /* _LIST_H_ */
