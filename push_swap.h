#ifndef	PUSH_SWAP_H
# define	PUSH_SWAP_H

typedef struct s_stack
{
	long			num;
	long			idx;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

# include "libft/libft.h"
# include <stdio.h>

void	ft_error();
long    ft_assign_idx(char **results, long num);
t_stack	*ft_new_node(long num, char **results);
void 	ft_append_node(t_stack **head, t_stack *node);
t_stack	**ft_get_stack(char **results);
int		ft_is_duplicated(t_stack **a);
int     ft_is_valid_input(t_stack **a);
t_stack	*ft_lst_last(t_stack *lst);
int		ft_is_sorted(t_stack **a);
long	ft_stack_size(t_stack **a);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void    ft_ss(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void    ft_rr(t_stack **a, t_stack **b);
void    ft_rra(t_stack **a);
void    ft_rrb(t_stack **b);
void    ft_rrr(t_stack **a, t_stack **b);
long    ft_min_num(t_stack **stack);
long    ft_max_num(t_stack **stack);
int	    ft_find_pos(t_stack **a, int value);
// long    ft_find_pos(t_stack **stack, long cur);
// long    ft_mid_num(t_stack **stack);
// long    ft_get_count(t_stack **a, t_stack **b, long cur);
// long    ft_best_num(t_stack **a, t_stack **b);
// void    ft_sort_num(t_stack **a, t_stack **b);
void    ft_small_sort(t_stack **a);
// void    ft_radix_sort(t_stack **a);

// void    print_stack(t_stack **stack);
// void    print_stack_A(t_stack **stack);
// void    print_stack_B(t_stack **stack);
// t_top   *ft_get_top(t_stack **a, t_stack **b);

#endif