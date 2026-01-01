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
    max_idx = tmp->idx;
    while (tmp)
    {
        if (tmp->idx > max_idx)
            max_idx = tmp->idx;
        tmp = tmp->next;
    }
    return (max_idx);
}

static long	ft_pos_in_stack(t_stack **a, long idx)
{
	t_stack	*tmp;
	long	i;

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

static long ft_ops_count(long idx, long pos, t_stack **a, t_stack **b)
{
    long    Pos_in_A;
    long    Pos_in_B;
    long    result;

    Pos_in_A = ft_pos_in_stack(a, idx);
    Pos_in_B = ft_pos_in_stack(b, pos);
    if ((Pos_in_A > (ft_stack_size(a)) / 2 && Pos_in_B <= (ft_stack_size(b)) / 2))
        return (ft_stack_size(a) - Pos_in_A + Pos_in_B + 1);
    else if (Pos_in_A <= (ft_stack_size(a)) / 2 && Pos_in_B > (ft_stack_size(b)) / 2)
        return (Pos_in_A + ft_stack_size(b) - Pos_in_B + 1);
    if (Pos_in_A >= Pos_in_B)
    {
        if (Pos_in_A <= ft_stack_size(a) / 2)
            result = Pos_in_A;
        else
            result = ft_stack_size(a) - ft_pos_in_stack(a, idx);
    }
    else
    {
        if (Pos_in_B <= ft_stack_size(b) / 2)
            result = Pos_in_B;
        else
            result = ft_stack_size(b) - ft_pos_in_stack(b, pos);
    }
    return (result + 1);
}

static long ft_cheapest_num(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    long    pos;
    long    min_count;
    long    best_idx;

    tmp = *a;
    // printf ("Start idx => %li\n", tmp->idx);
    pos = ft_find_idx_pos(tmp->idx, b);
    // printf ("Pos in B => %li\n", pos);
    min_count = ft_ops_count(tmp->idx, pos, a, b);
    // printf ("Min_count => %li\n", min_count);
    best_idx = tmp->idx;
    // printf ("Best_idx => %li\n", best_idx);
    while (tmp)
    {
        pos = ft_find_idx_pos(tmp->idx, b);
        // printf ("Ops_count for %li = %li\n", tmp->idx, ft_ops_count(tmp->idx, pos, a, b));
        if (ft_ops_count(tmp->idx, pos, a, b) < min_count)
        {
            min_count = ft_ops_count(tmp->idx, pos, a, b);
            best_idx = tmp->idx;
        }
        tmp = tmp->next;
    }
    printf ("Best_idx (C) => %li\n", best_idx);
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

// static void pos_test(t_stack **a, t_stack **b)
// {
    // printf ("Stack_A => ");
    // print_idx(a);
    // printf ("Stack_B => ");
    // print_idx(b);
    // while ((*a))
    // {
    //     pos = ft_find_idx_pos((*a)->idx, b);
    //     printf("Idx = %li, Pos = %li.\n", (*a)->idx,  ft_find_idx_pos((*a)->idx, b));
    //     printf("Idx = %li, Ops_count = %li.\n", (*a)->idx,  ft_ops_count((*a)->idx, pos, a, b));
    //     *a = (*a)->next;
    // }
// }

static void ft_push_pattern(long idx, long pos, t_stack **a, t_stack **b)
{
    long    Pos_in_A;
    long    Pos_in_B;

    Pos_in_A = ft_pos_in_stack(a, idx);
    Pos_in_B = ft_pos_in_stack(b, pos);
    printf ("Idx = %li, Pos = %li\n", idx, pos);
    printf ("Pos_in_A = %li, Pos_in_B = %li\n", ft_pos_in_stack(a, idx), ft_pos_in_stack(b, pos));
    printf("Cheapest Num = %li, ops_count = %li\n", ft_cheapest_num(a, b), ft_ops_count(idx, pos, a, b));
    if (Pos_in_A <= ft_stack_size(a)/2 && Pos_in_B <= ft_stack_size(b)/2)
    {
        while (Pos_in_A != 0 && Pos_in_B != 0)
        {
            ft_rr(a, b);
            Pos_in_A--;
            Pos_in_B--;
        }
    }
    if (Pos_in_A > ft_stack_size(a)/2 && Pos_in_B > ft_stack_size(b)/2)
    {
        while (Pos_in_A != ft_stack_size(a) - 1 && Pos_in_B != ft_stack_size(b) - 1)
        {
            ft_rrr(a, b);
            Pos_in_A++;
            Pos_in_B++;
        }
    }
    if (Pos_in_A <= ft_stack_size(a)/2)
    {
        while (Pos_in_A != 0)
        {
            ft_rb(a);
            Pos_in_A--;
        }
    }
    else
    {
        while (Pos_in_A != ft_stack_size(a))
        {
            ft_rrb(a);
            Pos_in_A++;
        }
    }
    if (Pos_in_B <= ft_stack_size(b)/2)
    {
        while (Pos_in_B != 0)
        {
            ft_rb(b);
            Pos_in_B--;
        }
    }
    else
    {
        while (Pos_in_B != ft_stack_size(b))
        {
            ft_rrb(b);
            Pos_in_B++;
        }
    }
}

void    ft_radix_sort(t_stack **a)
{
    t_stack **b;
    long    idx;
    long    pos;
    long    max_pos_in_B;

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
    max_pos_in_B = ft_pos_in_stack(b, ft_max_idx(b));
    if (max_pos_in_B <= ft_stack_size(b)/2)
    {
        while ((*b)->idx != ft_max_idx(b))
            ft_rb (b);
    }
    else
    {
        while ((*b)->idx != ft_max_idx(b))
            ft_rrb (b);
    }
    ft_rrb (a);
    // while (ft_stack_size(b) != 0)
    // {
    //     if ((*a)->idx )
    //     ft_pa(a, b);
    // }
    printf ("Stack_A => ");
    print_idx(a);
    printf ("Stack_B => ");
    print_idx(b);
}
