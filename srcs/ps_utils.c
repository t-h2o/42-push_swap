#include	"push_swap.h"

void
	ps_push(plate **src, plate **dst)
{
	plate	*b;
	if (!*src)
		return ;
	if (!*dst)
	{
		*dst = *src;
		*src = (*src)->down;
		(*src)->up = 0;
		(*dst)->down = 0;
	}
	else
	{
		(*dst)->up = *src;
		*src = (*src)->down;
		if (*src)
			(*src)->up = 0;
		b = (*dst);
		*dst = (*dst)->up;
		(*dst)->down = b;
	}
}

void
	ps_reverse_rotate(plate **a)
{
	plate	*b;
	plate	*y;
	plate	*end;

	b = *a;
	end = *a;
	while (end->down)
	{	y = end;
		end = end->down;
	}
	y->down = 0;
	end->down = *a;
	*a = end;
}

void
	ps_rotate(plate **a)
{
	plate	*b;
	plate	*z;

	if (!*a)
		return ;
	b = (*a)->down;
	z = b;
	while (z->down)
		z = z->down;
	z->down = *a;
	(*a)->up = z;
	(*a)->down = 0;
	b->up= 0;
	*a = b;
}

void
	ps_swap(plate *x)
{
	int	tmp;

	if (!x)
		return ;
	tmp = x->n;
	x->n = x->down->n;
	x->down->n = tmp;
}

int
	ps_atoi(char *s)
{
	int	minus = 1;
	int	r;

	r = 0;
	if (*s == '-')
		minus = -1;
	if (*s == '-')
		s++;
	while (*s)
	{
		r = (*s - '0') + (r * 10);
		s++;
	}
	return (r * minus);
}

