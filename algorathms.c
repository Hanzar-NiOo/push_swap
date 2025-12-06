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

long    ft_get_count(t_stack **a, t_stack **b, long cur)
{
    long    pos;
    long    count;
    t_stack *tmp_a;
    t_stack *tmp_b;

    tmp_a = *a;
    tmp_b = *b;
    pos = ft_find_pos(b, tmp_b->num);
    count = 0;
    while (cur != (*a)->num && pos != (*b)->num)
    {
        if (cur != (*a)->num && pos != (*b)->num)
        {
            tmp_a = tmp_a->next;
            tmp_b = tmp_b->next;
        }
        else if (cur != (*a)->num && pos == (*b)->num)
            tmp_a = tmp_a->next;
        else if (cur == (*a)->num && pos != (*b)->num)
            tmp_b = tmp_b->next;
        count++;
    }
    count++;
    return (count);
}

long    ft_best_num(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    long    min_count;
    long    best_num;

    tmp = *a;
    min_count = ft_get_count(a, b, tmp->num);
    while(tmp)
    {
        if (min_count > ft_get_count(a, b, tmp->num))
        {
            min_count = ft_get_count(a, b, tmp->num);
            best_num = tmp->num;
        }
        tmp = tmp->next;
    }
    return (best_num);
}

void    sort_num(t_stack **a, t_stack **b)
{
    ft_pb(a, b);
    ft_pb(a, b);
}
