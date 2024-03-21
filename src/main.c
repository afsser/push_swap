#include "../include/push_swap.h"

void	failure(int *nbrs)
{
	write(2, "Error\n", 6);
	free(nbrs);
	nbrs = NULL;
	exit(EXIT_FAILURE);
}

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
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				failure(nbrs);
			j++;
		}
		nbrs[i] = ft_atoi(argv[i]);
		i++;
	}
	return (nbrs);
}

int	main(int argc, char **argv)
{
	// t_data	*stack_a;
	// t_data	*stack_b;

	int	*nbrs;
	nbrs = parse_args(argc, argv);
	check_duplicates(nbrs, argc);

	// ================================== print nbrs
	int	i;
	for(i = 1; i < argc; i++)
		ft_printf("%d\n", nbrs[i]);
	// ================================== 
	return (EXIT_SUCCESS);
}