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
	// int				*index;
	// int				current_pos;
	// int				target_pos;
	// int				cost_a;
	// int				cost_b;
	int				nb;
	struct s_data	*index;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

void	check_args(int argc, char **argv);
void	failure_free(t_data *nbrs);
void 	failure(void);
void	parse_args(int argc, char **argv, t_data *nbrs);
t_data 	*bubble_sort(t_data *nbrs);
t_data 	*copy_list(int argc, char **argv);

#endif