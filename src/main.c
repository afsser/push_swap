/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcaldas- <fcaldas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:22:20 by fcaldas-          #+#    #+#             */
/*   Updated: 2024/06/19 15:41:25 by fcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_and_exit_with_message(t_data *nbrs, char *msg, int exit_code)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (nbrs != NULL)
	{
		if (nbrs->a != NULL)
			free(nbrs->a);
		if (nbrs->b != NULL)
			free(nbrs->b);
		if (nbrs != NULL)
			free(nbrs);
	}
	if (exit_code == 1)
		exit(EXIT_FAILURE);
	if (exit_code == 0)
		exit(EXIT_SUCCESS);
}

static void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		free_and_exit_with_message(NULL, "", 1);
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			free_and_exit_with_message(NULL, "Error\n", 1);
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				free_and_exit_with_message(NULL, "Error\n", 1);
			j++;
		}
	}
}

int	main(int argc, char **argv)
{
	t_data	*nbrs;

	check_args(argc, argv);
	nbrs = malloc(sizeof(t_data));
	if (nbrs == NULL)
		return (EXIT_SUCCESS);
	initialize_stacks(argc, argv, nbrs);
	exit_if_sorted_or_has_duplicate(nbrs, 0);
	create_index(nbrs);
	if (nbrs->a_size == 2 && nbrs->a[0] > nbrs->a[1])
		swap("sa", nbrs->a, nbrs->a_size);
	else if (nbrs->a_size == 3)
		sort_three_elements(nbrs);
	else if (nbrs->a_size >= 4 && nbrs->a_size <= 5)
		sort_four_to_five_elements(nbrs);
	else
		radix_sort(nbrs);
	free_and_exit_with_message(nbrs, NULL, 0);
	return (EXIT_SUCCESS);
}
