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

int main(int argc,char **argv)
{
    char    **results;
    t_stack **a;

    results = ft_results(argc, argv);
    if (!ft_check_results(results))
        ft_error();
    a = ft_get_stack(results);
    if (ft_is_duplicated(a) || ft_is_invalid_input(a))
        ft_error();
    print_stack(a);
    return (0);
}
