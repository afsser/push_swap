/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:38 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/06/19 16:05:07 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	long	*a;
	long	*b;
	int		a_size;
	int		b_size;
	int		changed;
}			t_data;

void		rotate(long *array, int size, char *direction, char *list);
void		swap(char *str, long *array, int size);
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
long		ft_atol(const char *n, t_data *nbrs);
long		get_max(t_data *nbrs);

#endif