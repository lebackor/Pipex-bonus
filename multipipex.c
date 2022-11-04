#include "pipex.h"

int	multipipe(t_data *p)
{
	int	i;

	i = -1;
	p->ac = p->ac - 3;
	printf("%d\n", p->ac);
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
