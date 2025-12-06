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

void	ft_sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;

	first = *a;
	second = (*a)->next;
	if (first && second)
	{
		first->next = second->next;
		// if (second->next)
		// 	second->next->prev = first;
		// first->prev = second;
		// second->prev = NULL;
		second->next = first;
		*a = second;
	}
	printf ("sa\n");
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!b || !*b)
		return ;
	tmp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = tmp;
	printf ("pa\n");
}

void	ft_ra(t_stack **a)
{
    t_stack	*first;
	t_stack	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	last = *a;
	while (last->next)
		last = last->next;
	first->next = NULL;
	last->next = first;
    printf ("ra\n");
}

void    ft_rra(t_stack **a)
{
    t_stack *first;
    t_stack *last;
    t_stack *new_last;

    if (!a || !*a || !(*a)->next)
        return ;
    first = *a;
    last = *a;
    while (last->next)
    {
        if (!last->next->next)
            new_last = last;
        last = last->next;
    }
    *a = last;
    last->next = first;
    new_last->next = NULL;
    printf("rra\n");
}
