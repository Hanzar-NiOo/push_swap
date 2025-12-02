/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:06:17 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 10:26:33 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*sa(t_stack *a)
{
	t_stack	*first;
	t_stack	*second;

	first = a;
	second = a->next;
	if (first && second)
	{
		first->next = second->next;
		if (second->next)
			second->next->prev = first;
		first->prev = second;
		second->prev = NULL;
		second->next = first;
	}
	printf ("sa\n");
	return (second);
}

// t_stack	*pa(t_stack *b, t_stack *a)
// {
// 	t_stack	*head;

// 	head = b;
// 	head->prev = NULL;
// 	head = a;
// 	a = head->next;
// 	a->prev = head;
// 	printf ("pa\n");
// 	return (a);
// }
