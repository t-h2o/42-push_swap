/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgrivel <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:13:08 by tgrivel           #+#    #+#             */
/*   Updated: 2022/01/03 16:44:48 by tgrivel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

/*	Check is there isn't same number
 *	if there is same number
 *		return (1)
 *	else
 *		return (0)
 */
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

/*	if the isn't enought arguments
 *		return (1)
 *	else
 *		return (0)
 */
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

/*	Check if the string 
 *	have only digit or not
 */
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
