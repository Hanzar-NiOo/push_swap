/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 23:30:58 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/06 23:34:25 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_ops_count(long idx, long pos, t_stack **a, t_stack **b)
{
	long	pos_in_a;
	long	pos_in_b;
	long	result;

	result = 0;
	pos_in_a = ft_pos_in_stack(a, idx);
	pos_in_b = ft_pos_in_stack(b, pos);
	if ((pos_in_a > (ft_stack_size(a)) / 2
			&& pos_in_b <= (ft_stack_size(b)) / 2))
		return (ft_stack_size(a) - pos_in_a + pos_in_b + 1);
	else if (pos_in_a <= (ft_stack_size(a)) / 2
		&& pos_in_b > (ft_stack_size(b)) / 2)
		return (pos_in_a + ft_stack_size(b) - pos_in_b + 1);
	if (pos_in_a >= pos_in_b && pos_in_a <= ft_stack_size(a) / 2)
		result = pos_in_a;
	else if (pos_in_a >= pos_in_b && pos_in_a > ft_stack_size(a) / 2)
		result = ft_stack_size(a) - ft_pos_in_stack(a, idx);
	else if (pos_in_a <= pos_in_b && pos_in_b <= ft_stack_size(b) / 2)
		result = pos_in_b;
	else if (pos_in_a <= pos_in_b && pos_in_b > ft_stack_size(b) / 2)
		result = pos_in_b;
	return (result + 1);
}

long	ft_cheapest_num(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	long	pos;
	long	min_count;
	long	best_idx;

	tmp = *a;
	pos = ft_find_idx_pos(tmp->idx, b);
	min_count = ft_ops_count(tmp->idx, pos, a, b);
	best_idx = tmp->idx;
	while (tmp)
	{
		pos = ft_find_idx_pos(tmp->idx, b);
		if (ft_ops_count(tmp->idx, pos, a, b) < min_count)
		{
			min_count = ft_ops_count(tmp->idx, pos, a, b);
			best_idx = tmp->idx;
		}
		tmp = tmp->next;
	}
	return (best_idx);
}
