/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <lebackor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:29:43 by lebackor          #+#    #+#             */
/*   Updated: 2022/11/08 17:08:15 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_data p)
{
	p.str = parse_split(&p);
	if (!p.str)
	{
		ft_free_table(p.paths);
		free(p.cmdargs);
		ft_putstr_fd(p.av[2], STDOUT_FILENO);
		ft_putstr_fd(": command not found\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	dup2(p.f1, STDIN_FILENO);
	dup2(p.end[1], STDOUT_FILENO);
	close(p.end[0]);
	close(p.end[1]);
	close(p.f1);
	close(p.f2);
	execve(p.str, p.avsplit, p.env);
	free(p.cmdargs);
	ft_free_table(p.paths);
	perror("");
	exit(1);
}

void	second_child(t_data p)
{
	p.strchild = parse_child(&p);
	if (!p.strchild)
	{
		ft_free_table(p.pathschild);
		free(p.cmdargschild);
		ft_putstr_fd(p.av[3], STDOUT_FILENO);
		ft_putstr_fd(": command not found\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	dup2(p.end[0], STDIN_FILENO);
	dup2(p.f2, STDOUT_FILENO);
	close(p.end[0]);
	close(p.end[1]);
	close(p.f1);
	close(p.f2);
	execve(p.strchild, p.avsplitchild, p.env);
	free(p.cmdargschild);
	ft_free_table(p.pathschild);
	perror("");
	exit(1);
}

void	pipex(t_data p)
{
	int	i;

	i = -1;
	pipe(p.end);
	p.parent = fork();
	if (p.parent < 0)
		return ;
	p.stock[0] = p.parent;
	if (p.parent == 0)
		child_process(p);
	p.parent = fork();
	if (p.parent < 0)
		return ;
	p.stock[1] = p.parent;
	if (p.parent == 0)
		second_child(p);
	while (++i < 1)
		waitpid(p.stock[i], &p.status, 0);
	close(p.f1);
	close(p.f2);
	close(p.end[0]);
	close(p.end[1]);
	exit(0);
}

int	main(int ac, char **av, char **envp)
{
	t_data	p;

	if (ac < 5)
		return (ft_printf("less than 4 arguments\n"));
	p = (t_data){0};
	p.av = av;
	p.ac = ac;
	p.env = envp;
	p.i = -1;
	p.stock = malloc(sizeof(int) * ((p.ac - 3) * 2));
	if (ac == 5)
	{
		p.f1 = open(av[1], O_RDONLY);
		p.f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (p.f1 < 0 || p.f2 < 0)
		{
			if (p.f1 < 0)
			{
				perror(av[1]);
				if (p.f2 >= 0)
					close(p.f2);
			}
			if (p.f2 < 0)
				close(p.f1);
			ft_exit_fail(&p);
		}
		pipex(p);
	}
	else
	{
		printf("more than 4\n");
		p.f1 = open(av[1], O_RDONLY);
		if (p.f1 < 0)
		{
			perror(av[1]);
			ft_exit_fail(&p);
		}
		p.f2 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (p.f1 < 0 || p.f2 < 0)
		{
			if (p.f1 < 0)
			{
				perror(av[1]);
				if (p.f2 >= 0)
					close(p.f2);
			}
			if (p.f2 < 0)
				close(p.f1);
			ft_exit_fail(&p);
		}
		multipipe(&p);
	}
}
