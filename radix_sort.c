/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:24:14 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 13:36:51 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_max_bits(int max)
{
	int	bits;

	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void    ft_radix_sort(t_stack **a)
{
    t_stack **b;
	int	i;
	int	j;
	int	size;
	int	max_bits;

    b = NULL;
    b = malloc(sizeof(t_stack *));
	size = ft_stack_size(a);
	max_bits = ft_max_bits(size - 1);

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->idx >> i) & 1)
				ft_ra(a);
			else
				ft_pb(a, b);
			j++;
		}
		while (*b)
			ft_pa(a, b);
		i++;
	}
}
