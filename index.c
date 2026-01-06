/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:52:09 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 13:17:10 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_min_idx(t_stack **stack)
{
	t_stack	*tmp;
	long	min_idx;

	tmp = *stack;
	min_idx = tmp->idx;
	while (tmp)
	{
		if (tmp->idx < min_idx)
			min_idx = tmp->idx;
		tmp = tmp->next;
	}
	return (min_idx);
}

long	ft_max_idx(t_stack **stack)
{
	t_stack	*tmp;
	long	max_idx;

	tmp = *stack;
	max_idx = tmp->idx;
	while (tmp)
	{
		if (tmp->idx > max_idx)
			max_idx = tmp->idx;
		tmp = tmp->next;
	}
	return (max_idx);
}

long	ft_pos_in_stack(t_stack **stack, long idx)
{
	t_stack	*tmp;
	long	i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		if (tmp->idx == idx)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
}

long	ft_find_idx_pos(long idx, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	if (idx > ft_max_idx(b) || idx < ft_min_idx(b))
		return (ft_max_idx(b));
	else
	{
		while (tmp && tmp->next)
		{
			if (idx < tmp->idx && idx > tmp->next->idx)
				return (tmp->next->idx);
			tmp = tmp->next;
		}
		if ((*b)->idx < idx && !tmp->next)
			return ((*b)->idx);
	}
	return (-1);
}
