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
	long				nb;
	struct s_data	*index;
	struct s_data	*next;
	struct s_data	*prev;
	int				changed;
}					t_data;

void	check_args(int argc, char **argv);
void	failure_free(t_data *nbrs);
void 	failure(void);
void	free_struct(t_data *nbrs);
void	parse_args(int argc, char **argv, t_data **nbrs);
void	replace_with_sequence(t_data *nbrs, int argc);
// t_data 	*bubble_sort(t_data *nbrs);

#endif