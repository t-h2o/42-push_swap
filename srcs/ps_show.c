#include	"./../headers/push_swap.h"

void
	ps_show(plate *top)
{
	int	i;
	i = 0;
	while (top)
	{
		if (!(top->up))
			printf("%d\t|\t%d\t%p\tup %p\t\tdown %p\n\n", i, top->n, top, top->up, top->down);
		else
			printf("%d\t|\t%d\t%p\tup %p\tdown %p\n\n", i, top->n, top, top->up, top->down);
		i++;
		top = top->down;
	}
	printf("\t|\tA\n");
	printf("\n\n\n\n");
}
