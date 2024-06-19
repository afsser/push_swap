#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	int		changed;
}			t_data;

void		rotate(int *array, int size, char *direction, char *list);
void		swap(char *str, int *array, int size);
void		push(char *str, t_data *nbrs);
void		sort_three_elements(t_data *nbrs);
void		sort_four_to_five_elements(t_data *nbrs);
void		radix_sort(t_data *nbrs);
void		parse_numbers(t_data *nbrs, char **argv, int argc);
void		create_index(t_data *nbrs);
void		initialize_stacks(int argc, char **argv, t_data *nbrs);
void		free_and_exit_with_message(t_data *nbrs, char *msg, int exit_code);
void		exit_if_sorted_or_has_duplicate(t_data *nbrs, int i);
int			is_array_sorted(t_data *nbrs);
int			ft_atol(const char *n, t_data *nbrs);

#endif