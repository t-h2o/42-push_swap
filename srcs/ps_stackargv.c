/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stackargv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:13:42 by tgrivel           #+#    #+#             */
/*   Updated: 2022/01/03 16:54:50 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/*	Return the number in a string
 */
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

/*	Add number one to one 
 *	in the chain list
 */
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
}

/*	free the stack
 *	struct by struct
 */
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

/*	Convert the arguments to a chain list
 *	error -> return 1
 *	goood -> return 0
 */
int
	ps_argc_to_stack(int argc, char **argv, plate **topa)
{
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
	free(tab);
	return (0);
}
