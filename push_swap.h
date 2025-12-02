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

void	ft_error(char *str);
t_stack	*new_node(long idx, long num);
void 	append_node(t_stack **head, t_stack *node);
t_stack	*get_stack(long s_idx, char **results);
int		is_duplicated(t_stack *a);
int		is_sorted(t_stack *a);
long	stack_size(t_stack *a);
t_stack	*sa(t_stack *a);
t_stack	*sb(t_stack *b);
t_stack	*pb(t_stack *b, t_stack *a);

#endif