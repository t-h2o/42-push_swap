#include	"./../headers/push_swap.h"

int
	ps_check_not_same(int *tab, int i)
{
	int	j;
	j = i;
	while (j--)
	{
		i = j;
		while (i--)
			if (tab[i] == tab[j])
			{
				printf("same number %d\n", tab[i]);
				return (1);
			}
	}
	return (0);
}

int
	ps_is_arg(int argc)
{
	if (argc == 1)
		printf("0 argument\n");
	if (argc == 2)
		printf("1 argument\n");
	if (argc < 3)
		return (1);
	return (0);
}

int
	ps_is_not_digit(char *s)
{
	while (*s)
	{
		if (!('0' <= *s && *s <= '9'))
		{
			printf("Error\nthere is letter...\n");
			return (1);
		}
		else
			s++;
	}
	return (0);
}
