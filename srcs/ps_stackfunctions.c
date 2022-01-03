/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stackfunctions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:54:53 by tgrivel           #+#    #+#             */
/*   Updated: 2022/01/03 16:53:13 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/*	swap the both 1st number of the stack
 */
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

/*	push the 1st number in the other stack
 *	for call it,
 *	the 1st argument is the source
 *	and 2nd argument is the destination
 */
void
	ps_push(plate **src, plate **dst)
{
	
	if (!*src)
		return ;
	if (!*dst)
	{
		(*dst) = *src;
		*src = (*src)->down;
		(*dst)->down = 0;
	}
	else
	{
		plate	*tmp;

		tmp = *dst;
		*dst = *src;
		*src = (*src)->down;
		(*dst)->down = tmp;
	}
}

/*	put the last number on the top
 */
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

/*	put the 1st number on the bottom
 */
void
	ps_rotate(plate **a)
{
	plate	*tmp;
	plate	*ptr;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->down;
	ptr = *a;
	while (ptr->down)
		ptr = ptr->down;
	ptr->down = tmp;
	ptr->down->down = 0;
}
