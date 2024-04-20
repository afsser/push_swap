#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

// =========== TIRAR DEPOIS ===========
# include <stdio.h>
// =========== TIRAR DEPOIS ===========

typedef struct s_data
{
	int				index;
	int				nb;
	struct s_data	*next;
	struct s_data	*prev;
	int				changed;
	// int				current_pos;
	// int				target_pos;
	// int				cost_a;
	// int				cost_b;
}					t_data;

void	check_args(int argc, char **argv);
void	failure_free(t_data *nbrs);
void 	failure(void);
void	free_struct(t_data *nbrs);
void	create_stack(int argc, char **argv, t_data **nbrs);
void	replace_with_sequence(t_data *nbrs, int argc);
int		is_sorted(t_data *stack_a);
t_data	*get_min(t_data *stack);
t_data	*get_max(t_data *stack);
int	find_min(t_data *nbrs);
t_data	*find_last_node(t_data *head);
int		stack_len(t_data *lst);
t_data	*find_last_node(t_data *node);
int		stack_len(t_data *stack);
void	push_swap(t_data **stack_a, t_data **stack_b);
void	sa(t_data **stack_a, int checker);
void	sb(t_data **stack_b, int checker);
void	ss(t_data **stack_a, t_data **stack_b, int checker);
void	pa(t_data **stack_b, t_data **stack_a, int checker);
void	pb(t_data **stack_a, t_data **stack_b, int checker);
void	ra(t_data **stack_a, int checker);
void	rb(t_data **stack_b, int checker);
void	rr(t_data **stack_a, t_data **stack_b, int checker);
void	rra(t_data **stack_a, int checker);
void	rrb(t_data **stack_b, int checker);
void	rrr(t_data **stack_a, t_data **stack_b, int checker);
// t_data 	*bubble_sort(t_data *nbrs);

#endif