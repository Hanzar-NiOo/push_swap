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

void	ft_sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;

	first = *b;
	second = (*b)->next;
	if (first && second)
	{
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		first->prev = second;
		second->prev = NULL;
		second->next = first;
		*b = second;
	}
	printf ("sa\n");
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!a || !*a)
		return ;
	tmp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = tmp;
	printf ("pb\n");
}

void    ft_rb(t_stack **b)
{
    t_stack *first;
    t_stack *last;

    if (!b || !*b || !(*b)->next)
        return ;
    first = *b;
    *b = (*b)->next;
    last = *b;
    while (last->next)
        last = last->next;
    first->next = NULL;
    last->next = first;
    printf ("rb\n");
}
