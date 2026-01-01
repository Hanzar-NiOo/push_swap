/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:33:42 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/01 23:10:42 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_sort_three(t_stack **a)
{
    int	first;
	int	second;
	int	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if (first > second && second < third && first < third)
		ft_sa(a);
	else if (first > second && second > third)
	{
		ft_sa(a);
		ft_rra(a);
	}
	else if (first > second && second < third && first > third)
		ft_ra(a);
	else if (first < second && second > third && first < third)
	{
		ft_sa(a);
		ft_ra(a);
	}
	else if (first < second && second > third && first > third)
		ft_rra(a);
}

static void ft_min_move_top(t_stack **a, long size)
{
    int	    min;
	int	    pos;
    
	min = ft_min_num(a);
	pos = ft_find_pos(a, min);
    if (pos == 1)
        ft_ra (a);
    else if (pos == 2)
    {
        ft_ra (a);
        ft_ra (a);
    }
    else if (pos == 3)
    {
        if (size == 5)
            ft_rra(a);
        ft_rra(a);
    }
    else if (pos == 4)
        ft_rra(a);
}

void    ft_small_sort(t_stack **a)
{
    t_stack **b;

    b = NULL;
    b = malloc(sizeof(t_stack *));
    if (ft_stack_size(a) == 2)
        ft_sa(a);
    else if (ft_stack_size(a) == 3)
        ft_sort_three(a);
    else if (ft_stack_size(a) == 4 || ft_stack_size(a) == 5)
    {
        if (ft_stack_size(a) == 5)
        {
            ft_min_move_top(a, ft_stack_size(a));
            ft_pb (a, b);
        }
        ft_min_move_top(a, ft_stack_size(a));
        ft_pb (a, b);
        ft_sort_three (a);
        if (ft_stack_size(b) == 2)
            ft_pa (a, b);
        ft_pa (a, b);
    }
}
