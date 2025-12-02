/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:31:43 by hnioo             #+#    #+#             */
/*   Updated: 2025/12/02 11:48:13 by hnioo            ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char		**results;
	t_stack		**a;

	a = NULL;
	if (argc < 2)
		ft_error("argv Error");
	if (argc == 2)
	{
		results = ft_split(argv[1], ' ');
		a = ft_get_stack(0, results);
		free_split(results);
	}
	else if (argc > 2)
		a = ft_get_stack(1, argv);
	if (!a)
	{
		ft_error("Stack is empty");
		free (a);
	}
	// else if (is_duplicated(a))
	// {
	// 	ft_error("Num is dup!");
	// 	free (a);
	// 	a = NULL;
	// }
	// if (is_sorted(a))
	// {
	// 	printf("Stack is already sorted!!!");
	// 	return (0);
	// }
	// else if (stack_size(a) == 2)
	// 	a = sa(a);
	// else if (stack_size(a) > 2)
	// {
	// t_stack	*b;
	// b = NULL;
	// b = pb(b, a);
	
	printf ("size = %li\n", ft_stack_size(a));
	while (*a)
	{
		printf ("idx %li = ", (*a)->idx);
		printf ("%li\n", (*a)->num);
		(*a) = (*a)->next;
	}
	// }
	return (0);
}
