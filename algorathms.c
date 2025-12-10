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
    count = 0;
    while (cur != tmp_a->num || pos != tmp_b->num)
    {
        if (cur != tmp_a->num)
            tmp_a = tmp_a->next;
        if (pos != tmp_b->num)
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
    best_num = tmp->num;
    while(tmp)
    {
        if (min_count > ft_get_count(a, b, tmp->num))
        {
            min_count = ft_get_count(a, b, tmp->num);
            best_num = tmp->num;
        }
        else if (min_count == ft_get_count(a, b, tmp->num))
        {
            if (tmp->num > ft_max_num(b) || tmp->num < ft_min_num(b))
                best_num = tmp->num;
        }
        tmp = tmp->next;
    }
    return (best_num);
}

void    ft_sort_num(t_stack **a, t_stack **b)
{
    long    best_num;
    long    pos;
    long    size;

    ft_pb(a, b);
    ft_pb(a, b);
    size = ft_stack_size(a);
    while (size > 3)
    {
        pos = ft_find_pos(b, (*a)->num);
        best_num = ft_best_num(a, b);
        while ((*a)->num != best_num || (*b)->num != pos)
        {
            if ((*a)->num != best_num && (*b)->num != pos)
                ft_rr(a, b);
            else if ((*a)->num != best_num && (*b)->num == pos)
                ft_ra(a);
            else if ((*a)->num == best_num && (*b)->num != pos)
                ft_rb(b);
            ft_pb(a, b);
        }
        print_stack_A(a);
        print_stack_B(b);
        printf("best_num = %li, ",  best_num);
        printf("%li's pos = %li, ", best_num, pos);
        printf(", Count = %li\n", ft_get_count(a, b, ((*a)->num)));
        ft_pb(a, b);
        printf("\n");
        size--;
    }
    // if (ft_stack_size(a) == 3)
    // {
    //     if ((*a)->num > )
    // }
}
