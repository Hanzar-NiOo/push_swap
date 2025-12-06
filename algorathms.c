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

long    ft_best_num(t_stack **a)
{
    t_stack *tmp;
    // long    count;
    // long    pos;
    // long    cur;

    tmp = *a;
    // pos = ft_find_pos(b, tmp->num);
    // if (tmp->num != (*a)->num && pos != (*b)->num)
    //     ft_rr(a, b);
    while (tmp)
    {
        printf ("%li\n", tmp->num);
        printf ("%li\n", (*a)->num);
        tmp = tmp->next;
    }
    return (tmp->num);
}

void    sort_num(t_stack **a, t_stack **b)
{
    ft_pb(a, b);
    ft_pb(a, b);
}
