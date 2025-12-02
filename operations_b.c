/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:24:14 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 10:53:54 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sb(t_stack *b)
{
	t_stack	*first;
	t_stack	*second;

	first = b;
	second = b->next;
	if (first && second)
	{
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		first->prev = second;
		second->prev = NULL;
		second->next = first;
	}
	printf ("sb\n");
	return (second);
}

t_stack	*pb(t_stack *a, t_stack *b)
{
	// t_stack	*a_head;
	t_stack	*b_head;

	// append_node(&b, a);
	// b_head = b;
	// b = a;
	// b->next = b_head;
	// b->prev = NULL;
	// b_head->prev = b;
	// a_head = a->next;
	// a = a_head;
	if (!b)
	{
		b_head = a;
		b = b_head;
		b->prev = NULL;
		b->next = NULL;
	}
	// a->prev = NULL;
	return (b);
}
