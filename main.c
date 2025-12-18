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

static void    print_stack(t_stack **stack)
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

int main(int argc,char **argv)
{
    char    **results;
    t_stack **a;

    results = ft_results(argc, argv);
    int idx = 0;
    while (results[idx])
        printf ("%s\n", results[idx++]);
    a = ft_get_stack(results);
    print_stack(a);
    return (0);
}

// char    **results(int argc, char **argv)
// {
// 	char		**results;

// 	if (argc < 2)
// 		ft_error();
// 	else if (argc == 2)
// 	{
// 		results = ft_split(argv[1], ' ');
// 		free_split(results);
//         return (results);
// 	}
// 	else
//         results = (argv[1]);
//     return (results);
// 	if (!a)
// 		ft_error();
// 	else if (ft_is_duplicated(a))
// 	{
// 		ft_error();
// 		free (a);
// 	}
// 	else if (ft_is_sorted(a))
// 		printf("Stack is already sorted!!!\n");
// 	else if (ft_stack_size(a) == 2)
// 		ft_sa(a);
// 	else if (ft_stack_size(a) > 2)
// 	{
//         b = malloc(sizeof(t_stack *));
//         ft_sort_num(a, b);
	// }
	// return (0);
// }
