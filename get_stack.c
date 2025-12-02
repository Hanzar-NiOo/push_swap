/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 22:27:53 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 11:04:23 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_node(long idx, long num)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->idx = idx;
	node->num = num;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void append_node(t_stack **head, t_stack *node)
{
    t_stack *tmp;

    if (*head == NULL)
    {
        *head = node;
        return;
    }
    tmp = *head;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = node;
    node->prev = tmp;
}

t_stack	**ft_get_stack(long s_idx, char **results)
{
	t_stack		**a;
	t_stack		*node;
	long		num;
	long		idx;

	a = NULL;
	idx = 0;
	while (results[s_idx])
	{
		num = ft_atoi(results[s_idx]);
		node = new_node(idx++, num);
		append_node(&a, node);
		s_idx++;
	}
	return (a);
}

long	stack_size(t_stack *a)
{
	long	idx;

	idx = 0;
	while (a)
	{
		idx++;
		a = a->next;
	}
	return (idx);
}
