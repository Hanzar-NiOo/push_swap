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

// static void	ft_rotate_stack(long pos, t_stack **stack, char stack_name)
// {
// 	if (pos <= ft_stack_size(stack) / 2)
// 	{
// 		while (pos != 0)
// 		{
// 			if (stack_name == 'A')
// 				ft_ra(stack);
// 			else
// 				ft_rb(stack);
// 			pos--;
// 		}
// 	}
// 	else
// 	{
// 		while (pos != ft_stack_size(stack))
// 		{
// 			if (stack_name == 'A')
// 				ft_rra(stack);
// 			else
// 				ft_rrb(stack);
// 			pos++;
// 		}
// 	}
// }

static void	ft_rotate_stack_a(long pos, t_stack **a, long lst_idx_in_b)
{
	if (pos <= ft_stack_size(a) / 2)
	{
		while (pos != 0)
		{
			if (pos == 1 && ((*a)->idx > (*a)->next->idx) && ((*a)->idx < lst_idx_in_b))
				ft_sa(a);
			else
				ft_ra(a);
			pos--;
		}
	}
	else
	{
		while (pos != ft_stack_size(a))
		{
			ft_rra(a);
			pos++;
		}
	}
}

static void	ft_rotate_stack_b(long pos, t_stack **b)
{
	if (pos <= ft_stack_size(b) / 2)
	{
		while (pos != 0)
		{
			ft_rb(b);
			pos--;
		}
	}
	else
	{
		while (pos != ft_stack_size(b))
		{
			ft_rrb(b);
			pos++;
		}
	}
}

static void	ft_push_pattern(long idx, long pos, t_stack **a, t_stack **b)
{
	long	pos_in_a;
	long	pos_in_b;
	t_stack	*last_node;
	t_stack	**tmp;

	pos_in_a = ft_pos_in_stack(a, idx);
	pos_in_b = ft_pos_in_stack(b, pos);
	while (pos_in_a <= ft_stack_size(a) / 2 && pos_in_a != 0 && pos_in_b != 0
		&& pos_in_b <= ft_stack_size(b) / 2)
	{
		ft_rr(a, b);
		pos_in_a--;
		pos_in_b--;
	}
	while (pos_in_a > ft_stack_size(a) / 2 && pos_in_a != ft_stack_size(a) - 1
		&& pos_in_b != ft_stack_size(b) - 1 && pos_in_b > ft_stack_size(b) / 2)
	{
		ft_rrr(a, b);
		pos_in_a++;
		pos_in_b++;
	}
	// ft_rotate_stack(pos_in_a, a, 'A');
	// ft_rotate_stack(pos_in_b, b, 'B');
	ft_rotate_stack_b(pos_in_b, b);
	tmp = b;
	last_node = ft_lst_last(*tmp);
	ft_rotate_stack_a(pos_in_a, a, last_node->idx);
}

static void	ft_final_push_to_a(t_stack **a, t_stack **b)
{
	long	max_pos_in_b;

	max_pos_in_b = ft_pos_in_stack(b, ft_max_idx(b));
	if (max_pos_in_b <= ft_stack_size(b) / 2)
	{
		while ((*b)->idx != ft_max_idx(b))
			ft_rb (b);
	}
	else
	{
		while ((*b)->idx != ft_max_idx(b))
			ft_rrb (b);
	}
	ft_pa (a, b);
	while (*b)
	{
		while ((*a)->idx != (*b)->idx + 1)
			ft_rra (a);
		ft_pa (a, b);
	}
}

void	ft_main_sort(t_stack **a)
{
	t_stack	**b;
	long	idx;
	long	pos;

	b = NULL;
	b = malloc(sizeof(t_stack *));
	ft_pb (a, b);
	ft_pb (a, b);
	while (ft_stack_size(a) > 3)
	{
		idx = ft_cheapest_num(a, b);
		pos = ft_find_idx_pos(idx, b);
		ft_push_pattern(idx, pos, a, b);
		ft_pb (a, b);
	}
	ft_sort_three(a);
	ft_final_push_to_a(a, b);
}
