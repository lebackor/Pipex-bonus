#include "pipex.h"

int	multipipe(t_data *p)
{
	int	i;

	i = -1;

	p->ifork = 1;
	printf("%d\n", p->ac);
	pipe(p->end);
	while (++i < p->ac)
	{
		p->parent = fork();
		if (p->parent < 0)
			return (0);
		p->stock[++p->ifork] = p->parent;
		if (p->parent == 0)
			mchild_process(p);
	}
	i = -1;
	while (++i < p->ac)
	{
		waitpid(p->stock[i], &p->status, 0);
	//	printf("%d\n", p->stock[i]);
	}
	return (1);
}
