/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:13:16 by tgrivel           #+#    #+#             */
/*   Updated: 2021/12/07 12:13:20 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

int
	main(int argc, char **argv)
{
	plate	*topa;
	plate	*topb;

	if (ps_is_arg(argc))
		return (0);

	topa = 0;
	topb = 0;
	
	if(ps_argc_to_stack(argc, argv, &topa))
		return (0);
	
	ps_scan(&topa, &topb);

	ps_free_stack(topa);	
	ps_free_stack(topb);	
}
