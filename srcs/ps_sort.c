/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:16:48 by tgrivel           #+#    #+#             */
/*   Updated: 2022/01/05 18:03:03 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int
	ps_count_list(plate *list)
{
	int	r;

	r = 0;
	while (list)
	{
		list = list->down;
		r++;
	}
	return r;
}

static int
	ps_minvalue(plate * topa, int lim)
{
	int	r;
	int	n;
	int	min;

	r = 0;
	n = 0;
	min = topa->n;
	while (topa)
	{
		printf("%d < %d\n", topa->n, min);
		if (topa->n > lim)
			if (topa->n < min)
			{
				min  = topa->n;
				r = n;
			}
		n++;
		topa = topa->down;
	}
	return (r);
}
static void
	ps_replace(plate ** topa)
{
	int		nbl;
	int		min;
	int		dec;
	plate	*ptr;
	
	nbl = ps_count_list(*topa);
	printf("there is %d struct\n", nbl);
	dec = 0;
	while (nbl--)
	{
		min = ps_minvalue(*topa, dec);
		ptr = *topa;
		printf("min is at %dth place\n", min);
		while (min--)
		{
			ptr = ptr->down;
		}
		ptr->n = dec;
		dec++;
	}
	return ;
}

void
	ps_sort(plate ** topa, plate ** topb)
{
	ps_replace(topa);
	ps_show(*topa, *topb);
	return ;
}
