#include "pipex.h"

int	multipipe(t_data *p, t_nb *nb)
{
	int	i;

	i = -1;
	//p->ifork = -1;
	pipe(p->end);
	while (++i < (p->ac - 3))
	{
		p->parent = fork();
		if (p->parent < 0)
			return (0);
		p->stock[i] = p->parent;
	//	printf("i = %d\n", p->stock[p->ifork]);
		if (p->parent == 0)
		{
			printf("Number = %d\n", nb->number);
			mchild_process(p, nb);
		}
		nb = nb->next;
	}
//	printf("%d\n", p->ac - 3);
	i = -1;
	while (++i < (p->ac - 3))
	{
		waitpid(p->stock[i], &p->status, 0);
		printf("%d\n", p->stock[i]);
	}
	return (1);
}
