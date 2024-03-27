#include "../include/push_swap.h"

void	failure(int *nbrs)
{
	write(2, "Error\n", 6);
	free(nbrs);
	nbrs = NULL;
	exit(EXIT_FAILURE);
}

// char **ft_atostr(int *nbrs, int argc)
// {
// 	char	**nbr_strs;
// 	int	i;

// 	nbr_strs = malloc(sizeof(char *) * argc);
// 	i = 0;
// 	while (i < argc)
// 	{
// 		nbr_strs[i] = ft_itoa(nbrs[i]);
// 		i++;
// 	}
// 	return (nbr_strs);
// }

void	check_duplicates(int *nbrs, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (nbrs[i] == nbrs[j])
				failure(nbrs);
			j++;
		}
		i++;
	}
}

int	*parse_args(int argc, char **argv)
{
	int	i;
	int	j;
	int	*nbrs;

	i = 1;
	nbrs = malloc(sizeof(int) * argc - 1);
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				failure(nbrs);
			j++;
		}
		// ft_printf("sign: %d\n", sign);
		nbrs[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	return (nbrs);
}

void	change_nbrs(int *nbrs, int argc)
{
	int	i;
	
	i = 0;
	while (i < argc)
	{
		nbrs[i] = i;
		i++;
	}
}


#include <stdio.h>

int	main(int argc, char **argv)
{
	// t_data	*stack_a;
	// t_data	*stack_b;
	int	*nbrs;

	nbrs = parse_args(argc, argv);
	check_duplicates(nbrs, argc);
	bubble_sort(nbrs, argc - 1);
	change_nbrs(nbrs, argc - 1);
	// ================================== print nbrs
	int	i;
	i = 0;
	while (i < argc - 1)
	{
		ft_printf("%d\n", nbrs[i]);
		i++;
	}
	// ================================== 
	return (EXIT_SUCCESS);
}