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
	// t_stack		**b;

	a = NULL;
	// b = NULL;
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
	if (!a)
		ft_error("Stack is empty");
	if (ft_is_duplicated(a))
	{
		ft_error("Num is dup!");
		free (a);
		a = NULL;
	}
	if (ft_is_sorted(a))
		printf("Stack is already sorted!!!");
	if (ft_stack_size(a) == 2)
		ft_sa(a);
	else if (ft_stack_size(a) > 2)
	{
        
	}
	return (0);
}
