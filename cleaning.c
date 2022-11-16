/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:26:04 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/16 16:25:47 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit_fail(t_data *p)
{
	if (p->str)
		free(p->str);
	if (p->strchild)
		free(p->strchild);
	if (p->cmdargschild)
		free(p->cmdargschild);
	if (p->cmdargs)
		free(p->cmdargs);
	if (p->avsplit)
		ft_free_table(p->avsplit);
	if (p->avsplitchild)
		ft_free_table(p->avsplitchild);
	if (p->paths)
		ft_free_table(p->paths);
	exit(0);
}

void	ft_exit(t_data *p, t_nb *nb)
{
	close(p->f1);
	close(p->f2);
	if (p->stock)
		free(p->stock);
	ft_free_liste(nb, p);
}

void	ft_free_liste(t_nb *nb, t_data *p)
{
	t_nb	*tmp;
	int		i;

	i = 0;
	while (i < (p->ac - 3))
	{
		tmp = nb;
		nb = nb->next;
		if (tmp)
			free(tmp);
		i++;
	}
	free(p);
}
