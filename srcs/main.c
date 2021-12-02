#include	"./../headers/pushswap.h"

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

int
	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	int	n = ps_atoi(argv[1]);
	printf("n : %d\n", n);
	
}
