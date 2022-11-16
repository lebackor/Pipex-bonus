/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multichilds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 15:30:02 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/16 15:30:03 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	mchild_process(t_data *p, t_nb *nb)
{
	(void) nb;
	p->str = parse_split(p, nb);
	if (!p->str)
	{
		ft_free_table(p->paths);
		free(p->cmdargs);
		ft_putstr_fd(p->av[2], STDOUT_FILENO);
		ft_putstr_fd(": command not found\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (nb->number == 1)
	{
		dup2(p->f1, STDIN_FILENO);
		dup2(p->end[1], STDOUT_FILENO);
	}
	else if (nb->number != (p->ac - 3))
		multidup(p, nb);
	else if (nb->number == (p->ac - 3))
		multidup(p, nb);
	closepipe(p, nb);
	ft_free_table(p->paths);
	execve(p->str, p->avsplit, p->env);
	free(p->cmdargs);
	perror("");
	exit(1);
}

void	multidup(t_data *p, t_nb *nb)
{
	if (nb->number != p->ac - 3)
	{
		if (nb->number % 2 == 0)
		{
			dup2(p->end[0], STDIN_FILENO);
			dup2(p->end2[1], STDOUT_FILENO);
		}
		else
		{
			dup2(p->end2[0], STDIN_FILENO);
			dup2(p->end[1], STDOUT_FILENO);
		}
	}
	else if (nb->number == (p->ac - 3))
	{
		if (nb->number % 2 == 0)
		{
			dup2(p->end[0], STDIN_FILENO);
			dup2(p->f2, STDOUT_FILENO);
		}
		else
		{
			dup2(p->end2[0], STDIN_FILENO);
			dup2(p->f2, STDOUT_FILENO);
		}
	}
}

void	closepipe(t_data *p, t_nb *nb)
{
	if (nb->number % 2 == 0)
	{
		close(p->end[0]);
		close(p->end2[1]);
		close(p->end2[0]);
		close(p->end[1]);
	}
	else
	{
		if (nb->number > 1)
		{
			close(p->end2[1]);
			close(p->end2[0]);
		}
		close(p->end[0]);
		close(p->end[1]);
	}
}
