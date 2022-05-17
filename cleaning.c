/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:26:04 by lebackor          #+#    #+#             */
/*   Updated: 2022/05/17 15:26:43 by lebackor         ###   ########.fr       */
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
