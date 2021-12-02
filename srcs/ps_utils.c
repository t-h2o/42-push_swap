#include	"./../headers/push_swap.h"

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

