#include "pipex.h"

t_nb	*create_liste(t_nb *p)
{
	p = malloc(sizeof(t_nb));
	if (!p)
		return (0);
	p->next = NULL;
	return (p);
}

t_nb	*ft_addback(t_nb *p, int i)
{
	t_nb	*t_pile;

	if (i == 1)
	{
		p->number = 1;
		p->next = NULL;
	}
	else
	{
		t_pile = p;
		while (t_pile->next != NULL)
			t_pile = t_pile->next;
		t_pile->next = NULL;
		t_pile->next = create_liste(p);
		if (!t_pile->next)
			return (0);
		t_pile->next->number = t_pile->number + 1;
		return (t_pile);
	}
	return (p);
}
