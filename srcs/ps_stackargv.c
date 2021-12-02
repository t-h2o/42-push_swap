#include	"./../headers/push_swap.h"

void
	ps_add_plate(plate **top, int n)
{
	plate	*ptr;
	plate	*new;

	new = malloc(sizeof(plate));
	new->n = n;
	new->down = 0;
	if (!*top)
	{
		*top = new;
		return ;
	}
	ptr = *top;
	while (ptr->down)
		ptr = ptr->down;
	ptr->down = new;
	new->up = ptr;
}

void
	ps_free_stack(plate *top)
{
	plate	*ptr;
	while (top)
	{
		ptr = top;
		top = top->down;
		printf("\t\tfree :\t%p\n", ptr);
		free(ptr);
	}
}
