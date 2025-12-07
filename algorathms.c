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
    pos = ft_find_pos(b, cur);
    // printf ("current = %li , pos = %li, [-4 90 26 0]\n", cur, pos);
    count = 0;
    // printf ("%li\n",  tmp_a->num);
    // printf ("%li\n",  tmp_b->num);
    while (cur != tmp_a->num || pos != tmp_b->num)
    {
        if (cur != tmp_a->num && pos != tmp_b->num)
        {
            tmp_a = tmp_a->next;
            tmp_b = tmp_b->next;
        }
        else if (cur != tmp_a->num && pos == tmp_b->num)
            tmp_a = tmp_a->next;
        else if (cur == tmp_a->num && pos != tmp_b->num)
            tmp_b = tmp_b->next;
        count++;
    }
    count++;
    // printf ("%li\n",  count);
    return (count);
}

long    ft_best_num(t_stack **a, t_stack **b)
{
    t_stack *tmp;
    long    min_count;
    long    best_num;

    tmp = *a;
    min_count = ft_get_count(a, b, tmp->num);
    best_num = tmp->num;
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

void    ft_sort_num(t_stack **a, t_stack **b)
{
    // long    best_num;
    // long    pos;
    long    size;

    printf("%li\n", ft_stack_size(a));
    ft_pb(a, b);
    ft_pb(a, b);
    size = ft_stack_size(a);
    while (size > 3)
    {
        // best_num = ft_best_num(a, b);
        // printf ("%li\n", best_num);
        // pos = ft_find_pos(b, best_num);
        // printf ("%li\n", pos);
        // if (best_num != (*a)->num && pos != (*b)->num)
        //     ft_rr(a, b);
        // else if (best_num != (*a)->num && pos == (*b)->num)
        //     ft_ra(a);
        // else if (best_num == (*a)->num && pos != (*b)->num)
        //     ft_rb(b);
        // ft_pb(a, b);
        size--;
    }
    // if (ft_stack_size(a) == 3)

}
