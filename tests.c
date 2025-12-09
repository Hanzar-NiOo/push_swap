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

void free_split(char **arr)
{
    int i = 0;
    while (arr[i])
        free(arr[i++]);
    free(arr);
}

void    print_stack_A(t_stack **stack)
{
    t_stack *top;
    t_stack *tmp;

    top = *stack;
    tmp = *stack;
    printf("Stack_A -> [ ");
    while (tmp)
    {
        printf("%li ", tmp->num);
        tmp = tmp->next;
    }
    printf ("]\n");
    *stack = top;
}

void    print_stack_B(t_stack **stack)
{
    t_stack *top;
    t_stack *tmp;

    top = *stack;
    tmp = *stack;
    printf("Stack_B -> [ ");
    while (tmp)
    {
        printf("%li ", tmp->num);
        tmp = tmp->next;
    }
    printf ("]\n");
    *stack = top;
}

// Stack Test
int main(int argc, char **argv)
{
	char		**results;
	t_stack		**a;
    t_stack     **b;

	a = NULL;
    b = NULL;
	if (argc < 2)
		ft_error("argv Error");
	else if (argc == 2)
	{
		results = ft_split(argv[1], ' ');
		a = ft_get_stack(0, results);
		free_split(results);
	}
	else if (argc > 2)
		a = ft_get_stack(1, argv);
    print_stack_A(a);
    b = malloc(sizeof(t_stack *));
    print_stack_B(b);
    printf ("Stack_A Size = %li\n", ft_stack_size(a));
    printf ("Stack_B Size = %li\n", ft_stack_size(b));
    ft_sort_num(a, b);
    return (0);
}
