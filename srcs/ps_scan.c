#include	"push_swap.h"

static int
	ps_strcmp(char *s1, char *s2)
{
	while (*s1)
		if (*(s1++) != *(s2++))
			return (0);
	return (1);
}

void
	ps_scan(plate **topa, plate **topb)
{
	char	*input;
	int		len;

	len = 5;
	input = (char *)malloc(len);

	while (len + 1)
		input[len--] = 0;

	ps_show(*topa, *topb);

	while (1)
	{
		printf("\nGive the command : ");
		scanf("%s", input);
	
		if (ps_strcmp(input, "q"))
		{
			printf("DONE\n\n");
			break ;
		}
		else if (ps_strcmp(input, "help"))
		{
			printf("help\n");
		}
		else
		{
			if (ps_strcmp(input, "ra"))
			{
				printf("rotate A\n");
				ps_rotate(topa);
				ps_show(*topa, *topb);
			}
			else if (ps_strcmp(input, "rb"))
			{
				printf("rotate B\n");
				ps_rotate(topb);
				ps_show(*topa, *topb);
			}
			else if (ps_strcmp(input, "rr"))
			{
				printf("rotate A & rotate B\n");
				ps_rotate(topa);
				ps_rotate(topb);
				ps_show(*topa, *topb);
			}
			else if (ps_strcmp(input, "sa"))
			{
				printf("swap A\n");
				ps_swap(*topa);
				ps_show(*topa, *topb);
			}
			else if (ps_strcmp(input, "sb"))
			{
				printf("swap B\n");
				ps_swap(*topb);
				ps_show(*topa, *topb);
			}
			else if (ps_strcmp(input, "ss"))
			{
				printf("swap A & swap B\n");
				ps_swap(*topa);
				ps_swap(*topb);
				ps_show(*topa, *topb);
			}
			else if (ps_strcmp(input, "pb"))
			{
				printf("push A on B\n");
				ps_push(topa, topb);
				ps_show(*topa, *topb);
			}
			else if (ps_strcmp(input, "pa"))
			{
				printf("push B on A\n");
				ps_push(topb, topa);
				ps_show(*topa, *topb);
			}
			else
				printf("didn't get it :(\n");
		}
	}
	free(input);
}

