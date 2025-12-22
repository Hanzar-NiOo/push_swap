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

long    ft_min_idx(t_stack **stack)
{
    t_stack *tmp;
    long    min_idx;

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

long    ft_max_idx(t_stack **stack)
{
    t_stack *tmp;
    long    max_idx;

    tmp = *stack;
    max_idx = tmp->num;
    while (tmp)
    {
        if (tmp->idx > max_idx)
            max_idx = tmp->idx;
        tmp = tmp->next;
    }
    return (max_idx);
}

static int	ft_find_pos2(t_stack **a, long idx)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
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

static long ft_find_idx_pos(long idx, t_stack **b)
{
    t_stack *tmp;

    tmp = *b;
    if (idx > ft_max_idx(b) || idx < ft_min_idx(b))
        return (ft_max_idx(b));
    else if (idx < tmp->idx)
    {
        while (tmp && tmp->next)
        {
            if (idx < tmp->idx && idx > tmp->next->idx)
                return (tmp->next->idx);
            tmp = tmp->next;
        }
    }
    else if (idx > tmp->idx)
    {
        while (tmp && tmp->next)
        {
            if (tmp->idx < idx && tmp->next->idx > idx)
                return (tmp->next->idx);
            tmp = tmp->next;
        }
    }
    return (0);
}

static long ft_ops_count(long idx, long pos, t_stack **a, t_stack **b)
{
    long    a_count;
    long    b_count;
    long    result;

    if (ft_find_pos2(a, idx) <= ft_stack_size(a) / 2)
        a_count = ft_find_pos2(a, idx);
    else
        a_count = ft_stack_size(a) - ft_find_pos2(a, idx);
    if (ft_find_pos2(b, pos) <= ft_stack_size(b) / 2)
        b_count = ft_find_pos(b, pos);
    else
        b_count = ft_stack_size(b) - ft_find_pos2(b, pos);
    if (a_count > b_count)
        result = a_count + 1;
    else
        result = b_count + 1;
    return (result);
}

static long ft_cheapest_num(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    long    pos;
    long    min_count;
    long    best_idx;

    tmp = *a;
    best_idx = tmp->idx;
    pos = ft_find_idx_pos(tmp->idx, b);
    min_count = ft_ops_count(tmp->idx, pos, a, b);
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

// static long	ft_max_bits(long num)
// {
// 	long	bits;

// 	bits = 0;
// 	while ((num >> bits) != 0)
// 		bits++;
// 	return (bits);
// }

void    ft_radix_sort(t_stack **a)
{
    t_stack **b;

    b = NULL;
    b = malloc(sizeof(t_stack *));
    ft_pb (a, b);
    ft_pb (a, b);
    ft_pb (a, b);
    ft_pb (a, b);
    // ft_cheapest_num(t_stack **a, t_stack **b);
    print_stack(b);
    print_idx(b);
    long    idx = 4;
    long    pos = ft_find_idx_pos(idx, b);
    // printf("%li\n", ft_find_idx_pos(idx, b));
    printf("%li\n", ft_ops_count(idx, pos, a, b));
    printf("%li\n", ft_cheapest_num(a, b));
}
