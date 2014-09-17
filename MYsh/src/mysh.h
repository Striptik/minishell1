/*
** mysh.h for minishell header in /home/loisel_k/taff/C/Systeme-Unix/minishell1/include
** 
** Made by Kevin LOISELEUR
** Login   <loisel_k@epitech.net>
** 
** Started on  Wed Dec 18 14:18:22 2013 Kevin LOISELEUR
** Last update Wed Feb 19 12:56:50 2014 Kevin LOISELEUR
*/

#ifndef _MYSH_H_
# define _MYSH_H_

typedef struct		s_env
{
  char			**env;
  char			*user;
  char			*path;
  char			*pwd;
  char			*oldpwd;
  char			*home;
  char			*shell;
}			t_env;

/*
** prompt du shell
*/

# define PS1		"KooKie'z shell>>"

/*
** Message d'erreur
*/

# define ERROR_ENV_NULL	" : command not find (Null environnement)\n"

typedef void (*sig_handler) (int);

/*
** Main functions
*/

void			minishell(char **env);
void			minishell_main(char **env);
void			minishell_main_env_null(void);
void			put_error_env_null(char *buf, char *error);

/*
** Tools
*/

t_listp			*init_env(char **tab);
t_listp			*init_path(t_listp *env);
t_listp			*cut_the_path(char *str);
int			count_char_before(char *str, int i);
char			**env_tab(t_listp *env);
void		signal_handler(int sig);

/*
** "Parsing"
*/
int			parse_my_read(char **av, t_listp *path);
int			is_builtin(char **av);
int			is_cmd(char **av, t_listp *path);

/*
** Exec
*/

void			exec_my_read(int res, char **av, t_listp *env, t_listp *path);
void			exec_builtin(char **av, t_listp *env, t_listp *path);
void			exec_cmd(char **av, t_listp *env, t_listp *path);
void			free_list(t_listp *env, t_listp *path);

/*
** Segmenteur
*/

int			gchar(char c);
int			my_count_word(char *str);
int			my_count_char(char *str);
int			go_to_next(int io, int i, char *str, char *tmp);
char			**create_word_tab(char *str);

/*
** Builtins
*/

int			my_exit(char *buf);

#endif /* _MYSH_H_  */
