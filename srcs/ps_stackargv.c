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

int
	ps_argc_to_stack(int argc, char **argv, plate **topa)
{
	// if error, return 1
	// if good, return 0

	int		*tab;
	int		i;

	if (ps_is_arg(argc))
		return (1);
	*topa = 0;
	tab = (int *)malloc(4 * (argc - 1));
	i = 0;
	while (argc-- > 1)
	{
		if (ps_is_not_digit(*++argv))
		{
			ps_free_stack(*topa);
			free(tab);
			return (1);
		}
		tab[i] = ps_atoi(*argv);
		ps_add_plate(topa, tab[i++]);
	}

	if (ps_check_not_same(tab, i))
	{
		ps_free_stack(*topa);
		free(tab);
		return (1);
	}
	return (0);
}
