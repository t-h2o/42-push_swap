/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_scan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:13:26 by tgrivel           #+#    #+#             */
/*   Updated: 2021/12/07 12:13:27 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		try;

	len = 5;
	input = (char *)malloc(len);
	try = 0;
	while (len + 1)
		input[len--] = 0;

	ps_show(*topa, *topb);

	while (1)
	{
		int	print = 1;
		try++;
		printf("\n\n%d\t| Give the command : ", try);
		scanf("%s", input);
		printf("\t| ");	
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
			}
			else if (ps_strcmp(input, "rb"))
			{
				printf("rotate B\n");
				ps_rotate(topb);
			}
			else if (ps_strcmp(input, "rr"))
			{
				printf("rotate A & B\n");
				ps_rotate(topa);
				ps_rotate(topb);
			}
			else if (ps_strcmp(input, "rra"))
			{
				printf("reverse rotate A\n");
				ps_reverse_rotate(topa);
			}
			else if (ps_strcmp(input, "rrb"))
			{
				printf("reverse rotate B\n");
				ps_reverse_rotate(topb);
			}
			else if (ps_strcmp(input, "rrr"))
			{
				printf("reverse rotate A & B\n");
				ps_reverse_rotate(topa);
				ps_reverse_rotate(topb);
			}
			else if (ps_strcmp(input, "sa"))
			{
				printf("swap A\n");
				ps_swap(*topa);
			}
			else if (ps_strcmp(input, "sb"))
			{
				printf("swap B\n");
				ps_swap(*topb);
			}
			else if (ps_strcmp(input, "ss"))
			{
				printf("swap A & B\n");
				ps_swap(*topa);
				ps_swap(*topb);
			}
			else if (ps_strcmp(input, "pb"))
			{
				printf("push A on B\n");
				ps_push(topa, topb);
			}
			else if (ps_strcmp(input, "pa"))
			{
				printf("push B on A\n");
				ps_push(topb, topa);
			}
			else
			{
				printf("didn't get it :(\n");
				try--;
				print = 0;
			}
			if (print)
			{
				printf("\n");
				ps_show(*topa, *topb);
			}

		}
	}
	free(input);
}

