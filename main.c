/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:31:43 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 13:58:13 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char    **ft_results(int argc, char **argv)
{
    char	**results;
    int     idx;
    int     arg_idx;

	if (argc < 2)
		ft_error();
	else if (argc == 2)
		results = ft_split(argv[1], ' ');
	else
    {
        idx = 0;
        arg_idx = 1;
        results = malloc((argc)*sizeof(char *));
        while (argv[arg_idx])
            results[idx++] = argv[arg_idx++];
        results[idx] = '\0';
    }
    return (results);
}

static int  ft_check_results(char **results)
{
    long    idx;
    long    char_idx;

    idx = 0;
    while (results[idx])
    {
        char_idx = 0;
        while (results[idx][char_idx])
        {
            if (char_idx == 0 && ((results[idx][char_idx] == '+') || (results[idx][char_idx] == '-')))
                char_idx++;
            else if ((results[idx][char_idx] >= 48) && (results[idx][char_idx] <= 57))
                char_idx++;
            else
                return (0);
        }
        idx++;
    }
    return (1);
}

void    print_stack(t_stack **stack)
{
    t_stack *top;
    t_stack *tmp;

    top = *stack;
    tmp = *stack;
    printf("Stack -> [ ");
    while (tmp)
    {
        printf("%li ", tmp->num);
        tmp = tmp->next;
    }
    printf ("]\n");
    *stack = top;
}

void    print_idx(t_stack **stack)
{
    t_stack *top;
    t_stack *tmp;

    top = *stack;
    tmp = *stack;
    printf("Index -> [ ");
    while (tmp)
    {
        printf("%li ", tmp->idx);
        tmp = tmp->next;
    }
    printf ("]\n");
    *stack = top;
}

int main(int argc,char **argv)
{
    char    **results;
    t_stack **a;

    results = ft_results(argc, argv);
    if (!ft_check_results(results))
        ft_error();
    a = ft_get_stack(results);
    if (ft_is_duplicated(a) || !ft_is_valid_input(a))
        ft_error();
    if (!ft_is_sorted(a))
    {
        if (ft_stack_size(a) <= 5)
            ft_small_sort(a);
        else
            ft_radix_sort(a);
    }
    return (0);
}

// Operations_check
// int main(int argc,char **argv)
// {
//     char    **results;
//     t_stack **a;
//     t_stack **b;

//     results = ft_results(argc, argv);
//     if (!ft_check_results(results))
//         ft_error();
//     a = ft_get_stack(results);
//     b = NULL;
//     if (ft_is_duplicated(a) || ft_is_invalid_input(a))
//         ft_error();
//     print_stack(a);
//     ft_sa(a);
//     printf ("Swap A => ");
//     print_stack(a);
//     ft_ra(a);
//     printf ("Rotate A => ");
//     print_stack(a);
//     ft_rra(a);
//     printf ("Reverse Rotate A => ");
//     print_stack(a);
//     b = malloc(sizeof(t_stack));
//     ft_pb(a, b);
//     ft_pb(a, b);
//     ft_pb(a, b);
//     printf ("Push B => ");
//     print_stack(a);
//     print_stack(b);
//     ft_sb(b);
//     printf ("Swap B => ");
//     print_stack(b);
//     ft_ra(b);
//     printf ("Rotate B => ");
//     print_stack(b);
//     ft_rra(b);
//     printf ("Reverse Rotate B => ");
//     print_stack(b);
//     printf ("Swap both => ");
//     ft_ss(a, b);
//     print_stack(a);
//     print_stack(b);
//     printf ("Rotate both => ");
//     ft_rr(a, b);
//     print_stack(a);
//     print_stack(b);
//     printf ("Reserve rotate both => ");
//     ft_rrr(a, b);
//     print_stack(a);
//     print_stack(b);
//     return (0);
// }
