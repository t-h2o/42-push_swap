#include	"./../headers/push_swap.h"

plate
	*ps_rotate(plate *a)
{
	plate	*b;
	plate	*z;

	b = a->down;
	z = b;
	while (z->down)
		z = z->down;

/*	printf("b : %p\t%d\n", b, b->n);	
	printf("z : %p\t%d\n", z, z->n);
*/	
	z->down = a;
	a->up = z;
	a->down = 0;
	b->up= 0;
	return (b);
}

void
	ps_swap(plate *x)
{
	int	tmp;

	tmp = x->n;
	x->n = x->down->n;
	x->down->n = tmp;
}

int
	main(int argc, char **argv)
{
	int		*tab;
	int		i;
	plate	*top;

	if (ps_is_arg(argc))
		return (0);
	top = 0;
	tab = (int *)malloc(4 * (argc - 1));
	i = 0;
	while (argc-- > 1)
	{
		if (ps_is_not_digit(*++argv))
		{
			ps_free_stack(top);
			free(tab);
			return (0);
		}
		tab[i] = ps_atoi(*argv);
		ps_add_plate(&top, tab[i++]);
	}

	if (ps_check_not_same(tab, i))
	{
		ps_free_stack(top);
		free(tab);
		return (0);
	}

	ps_show(top);
	
/*	ps_swap(top);
	ps_show(top);
*/
	top = ps_rotate(top);
	ps_show(top);

	ps_free_stack(top);	
}
/* The left number are on the top of the stack
 */
