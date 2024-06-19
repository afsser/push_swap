/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:29 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/06/19 16:06:53 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three_elements(t_data *nbrs)
{
	long	max;

	max = get_max(nbrs);
	if (nbrs->a[0] == max)
		rotate(nbrs->a, nbrs->a_size, "up", "a");
	else if (nbrs->a[1] == max)
		rotate(nbrs->a, nbrs->a_size, "down", "a");
	if (nbrs->a[0] > nbrs->a[1])
		swap("sa", nbrs->a, nbrs->a_size);
}

void	sort_four_to_five_elements(t_data *nbrs)
{
	while (nbrs->b_size <= 1)
	{
		if (nbrs->a[0] == 0 || nbrs->a[0] == 1)
			push("pb", nbrs);
		else
			rotate(nbrs->a, nbrs->a_size, "up", "a");
	}
	if (nbrs->b[0] == 0)
		swap("sb", nbrs->b, nbrs->b_size);
	if (nbrs->a[2] != 4)
	{
		if (nbrs->a[0] == 4)
			rotate(nbrs->a, nbrs->a_size, "up", "a");
		else
			rotate(nbrs->a, nbrs->a_size, "down", "a");
	}
	if (nbrs->a[0] > nbrs->a[1])
		swap("sa", nbrs->a, nbrs->a_size);
	push("pa", nbrs);
	push("pa", nbrs);
}

int	is_array_sorted(t_data *nbrs)
{
	int	i;

	i = 0;
	while (i < nbrs->a_size - 1)
	{
		if (nbrs->a[i] > nbrs->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	radix_sort_stack_b(t_data *nbrs, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(nbrs))
	{
		if (((nbrs->b[0] >> j) & 1) == 0)
			rotate(nbrs->b, nbrs->b_size, "up", "b");
		else
			push("pa", nbrs);
	}
	if (is_array_sorted(nbrs))
		while (nbrs->b_size != 0)
			push("pa", nbrs);
}

void	radix_sort(t_data *nbrs)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = nbrs->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = nbrs->a_size;
		while (size-- && !is_array_sorted(nbrs))
		{
			if (((nbrs->a[0] >> j) & 1) == 0)
				push("pb", nbrs);
			else
				rotate(nbrs->a, nbrs->a_size, "up", "a");
		}
		radix_sort_stack_b(nbrs, nbrs->b_size, bit_size, j + 1);
	}
	while (nbrs->b_size != 0)
		push("pa", nbrs);
}
