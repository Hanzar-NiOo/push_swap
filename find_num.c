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

long    ft_min_num(t_stack **stack)
{
    t_stack *tmp;
    long    min_num;

    tmp = *stack;
    min_num = tmp->num;
    while (tmp)
    {
        if (tmp->num < min_num)
            min_num = tmp->num;
        tmp = tmp->next;
    }
    return (min_num);
}

long    ft_max_num(t_stack **stack)
{
    t_stack *tmp;
    long    max_num;

    tmp = *stack;
    max_num = tmp->num;
    while (tmp)
    {
        if (tmp->num > max_num)
            max_num = tmp->num;
        tmp = tmp->next;
    }
    return (max_num);
}

long    ft_find_pos(t_stack **stack, long cur)
{
    t_stack *tmp;
    long    max_num;
    long    result;

    max_num = ft_max_num(stack);
    tmp = *stack;
    while (tmp)
    {
        if (tmp->num == max_num)
        {
            while (tmp->num > cur)
                tmp = tmp->next;
            result = tmp->num;
        }
        tmp = tmp->next;
    }
    return (result);
}

long    ft_find_mid(t_stack **stack)
{
    t_stack *tmp;
    long    idx;
    long    mid;
    long    result;

    tmp = *stack;
    if (ft_stack_size(stack) % 2 == 1)
        mid = (ft_stack_size(stack) + 1) / 2;
    else
        mid = ft_stack_size(stack) / 2;
    idx = 1;
    while (tmp)
    {
        if (mid == idx)
            result = tmp->num;
        tmp = tmp->next;
        idx++;
    }
    return (result);
}
