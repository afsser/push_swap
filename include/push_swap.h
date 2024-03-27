#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int				nb;
	// int				index;
	// int				current_pos;
	// int				target_pos;
	// int				cost_a;
	// int				cost_b;
	struct s_data	*index;
	struct s_data	*next;
	struct s_data	*prev;
}					t_data;

t_data *bubble_sort(t_data *nbrs);
t_data *copy_list(t_data *head);

#endif