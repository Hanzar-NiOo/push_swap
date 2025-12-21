/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:52:09 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 13:17:10 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_duplicated(t_stack **a)
{
	t_stack	*i;
	t_stack	*j;

	i = *a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->num == j->num)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int ft_is_valid_input(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp && tmp->next)
	{
        if (tmp->num >= 2147483647)
            return (0);
        else if (tmp->num <= -2147483648)
            return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_is_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp && tmp->next)
	{
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
