#include "pipex.h"

void	mchild_process(t_data *p)
{
	p->str = parse_split(p);
	//printf("%s\n", p->str );
	if (!p->str)
	{
		ft_free_table(p->paths);
		free(p->cmdargs);
		ft_putstr_fd(p->av[2], STDOUT_FILENO);
		ft_putstr_fd(": command not found\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	dup2(p->f1, STDIN_FILENO);
	dup2(p->end[1], STDOUT_FILENO);
//	close(p.end[0]);
//	close(p.end[1]);
//	close(p.f1);
//	close(p.f2);
	execve(p->str, p->avsplit, p->env);
	free(p->cmdargs);
	ft_free_table(p->paths);
	perror("");
	exit(1);
}
