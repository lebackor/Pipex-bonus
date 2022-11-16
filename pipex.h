/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:21:41 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/16 16:23:57 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>

typedef struct p_data{
	int				number;
	struct p_data		*next;
}	t_nb;

typedef struct s_data{
	char			**av;
	char			**env;
	char			*str;
	char			*strchild;
	char			**paths;
	char			**pathschild;
	char			*cmdargs;
	char			*cmdargschild;
	char			**avsplit;
	char			**avsplitchild;
	int				f1;
	int				f2;
	int				cmd1;
	int				cmd2;
	int				ac;
	int				end[2];
	int				end2[2];
	int				*stock;
	int				status;
	int				i;
	int				j;
	int				k;
	int				ifork;
	pid_t			parent;
}	t_data;

int			ft_printf(const char *str, ...);
long long	ft_count_nb(long long nb);
int			ft_putnbr_u(unsigned int nb);
int			ft_check_pourcent(char c, va_list args);
int			ft_put_hexa_min(unsigned int nb);
int			ft_put_hexa_maj(unsigned int nb);
int			ft_print_hexa(unsigned long long nb, int a, int *count);
int			ft_pointer(unsigned long long nb, int *count);
int			ft_putstr(char *str);
int			ft_putnbr(int nb);
int			ft_putchar(char c);
size_t		ft_strlen(const char *str);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_strcmp(char *s1, char *s2);
char		*parsing(t_data *p);
int			ft_strcmp(char *s1, char *s2);
char		**ft_split(char const *s, char c);
char		**ft_free_table(char **str);
char		*parse_split(t_data *p, t_nb *nb);
char		*ft_strjoin(char const *s1, char const *s2);
char		*parse_child(t_data *p);
void		ft_exit_fail(t_data *p);
void		ft_putstr_fd(char *s, int fd);
char		*parsep1(t_data *p);
char		*parsep2(t_data *p);
void		multipipe(t_data *p, t_nb *nb);
void		child_process(t_data *p, t_nb *nb);
void		mchild_process(t_data *p, t_nb *nb);
t_nb		*create_liste(t_nb *p);
t_nb		*ft_addback(t_nb *p, int i);
void		multidup(t_data *p, t_nb *nb);
void		closepipe(t_data *p, t_nb *nb);
void		closepipe2(t_data *p, t_nb *nb, int i);
void		ft_exit(t_data *p, t_nb *nb);
void		ft_free_liste(t_nb *nb, t_data *p);
#endif
