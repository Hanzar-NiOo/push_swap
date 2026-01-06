/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnioo <hnioo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 20:11:57 by hnioo             #+#    #+#             */
/*   Updated: 2026/01/07 00:56:16 by hnioo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	long			num;
	long			idx;
	struct s_stack	*next;
}	t_stack;

long	ft_assign_idx(char **results, long num);
t_stack	*ft_new_node(long num, char **results);
void	ft_append_node(t_stack **head, t_stack *node);
t_stack	**ft_get_stack(char **results);
int		ft_is_duplicated(t_stack **a);
int		ft_is_valid_input(t_stack **a);
int		ft_is_sorted(t_stack **a);
void	ft_error(void);
long	ft_stack_size(t_stack **a);
t_stack	*ft_lst_last(t_stack *lst);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
long	ft_min_idx(t_stack **stack);
long	ft_max_idx(t_stack **stack);
long	ft_find_idx_pos(long idx, t_stack **b);
long	ft_pos_in_stack(t_stack **stack, long idx);
void	ft_sort_three(t_stack **a);
void	ft_small_sort(t_stack **a);
long	ft_cheapest_num(t_stack **a, t_stack **b);
void	ft_main_sort(t_stack **a);

// Test
void	print_stack(t_stack **stack);
void	print_idx(t_stack **stack);

#endif
