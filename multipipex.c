#include "pipex.h"

int	multipipe(t_data *p, t_nb *nb)
{
	int	i;

	i = -1;
	while (++i < (p->ac - 3))
	{
		if (nb->number % 2 == 0)
			pipe(p->end2);
		else
			pipe(p->end);
		p->parent = fork();
		if (p->parent < 0)
			return (0);
		p->stock[i] = p->parent;
		if (p->parent == 0)
		{
			printf("Number = %d\n", nb->number);
			mchild_process(p, nb);
		}
		if (nb->number % 2 == 0)
		{
			close(p->end[0]);
			close(p->end2[1]);
		}
		else
		{
			if (i > 0)
				close(p->end2[0]);
			close(p->end[1]);
		}
		nb = nb->next;
	}
	i = -1;
	while (++i < (p->ac - 3))
	{
		waitpid(p->stock[i], &p->status, 0);
		printf("%d\n", p->stock[i]);
	}
	close(p->f1);
	close(p->f2);
	return (1);
}
