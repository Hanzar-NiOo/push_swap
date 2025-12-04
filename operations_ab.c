/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:06:17 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 14:05:27 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_ss(t_stack **a, t_stack **b)
{
	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
    ft_sa(a);
    ft_sb(b);
    printf ("ss\n");
}

void    ft_rr(t_stack **a, t_stack **b)
{
    if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
    ft_ra(a);
    ft_rb(b);
    printf("rr\n");
}

void    ft_rrr(t_stack **a, t_stack **b)
{
    if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
    ft_rra(a);
    ft_rrb(b);
    printf ("rrr\n");
}
