/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_show.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:13:32 by tgrivel           #+#    #+#             */
/*   Updated: 2022/01/03 16:02:19 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

static int
	ps_lstlen(plate *p)
{
	int	r;

	r = 0;
	while (p)
	{
		r++;
		p = p->down;
	}
	return (r);
}

static void
	ps_simple_display(plate *topa, plate *topb)
{
	int	lena;
	int	lenb;
	int	i;

	i = 0;
	lena = ps_lstlen(topa);
	lenb = ps_lstlen(topb);
	
	while (lena || lenb)
	{
		if (lena > lenb)
		{
			printf("%d\t|\t%d\n", i, topa->n);
			topa = topa->down;
			lena--;
		}
		else if (lenb > lena)
		{
			printf("%d\t|\t\t%d\n", i, topb->n);
			topb = topb->down;
			lenb--;
		}
		else
		{
			printf("%d\t|\t%d\t%d\n", i, topa->n, topb->n);
			topa = topa->down;
			topb = topb->down;
			lenb--;
			lena--;
		}
		i++;
	}
	printf("\n\t\tA\tB\n");
}

static void
	ps_dis_play(plate *p, char c)
{
	int	i;
	if (p)
		printf("\n\n");
	if (!p)
		return ;
	i = 0;
	while (p)
	{
		printf("%d\t|\t%d\t%p\tdown %p\n", i, p->n, p, p->down);
		i++;
		p = p->down;
	}
	printf("\n\t|\t%c\n", c);
}

void
	ps_show(plate *topa, plate *topb)
{
//	ps_simple_display(topa, topb);	

	ps_dis_play(topa, 'A');
	ps_dis_play(topb, 'B');
}
