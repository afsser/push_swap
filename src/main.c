#include "../include/push_swap.h"

void	change_nbrs(t_data *copy)
{
	int		i;
	t_data	*tmp;
	
	tmp = copy->index;
	i = 1;
	while (tmp)
	{
		tmp->nb = i;
		i++;
		tmp = tmp->next;
	}
}

void	get_address(t_data *nbrs, t_data *copy)
{
	while (nbrs)
	{
		copy->index = nbrs;
		copy->index->nb = nbrs->nb;
		nbrs = nbrs->next;
		copy = copy->next;
	}
}
	// t_data	*tmp;
	// t_data	*tmp2;

	// tmp = *nbrs;
	// tmp2 = *copy;

#include <stdio.h>

int	main(int argc, char **argv)
{
	// t_data	*stack_a;
	// t_data	*stack_b;
	// int		*nbrs;
	t_data	copy;
	t_data	nbrs;

	check_args(argc, argv);
	parse_args(argc, argv, &nbrs);
	parse_args(argc, argv, &copy);
	get_address(&nbrs, &copy);
	bubble_sort(&copy);
	// change_nbrs(&copy);
	// ================================== print nbrs

    while (nbrs.next) {
        printf("%d ", nbrs.nb);
		nbrs = *(nbrs.next);
    }

	// while (copy.next) {
    //     printf("%d ", copy.nb);
	// 	copy = *(copy.next);
    // }

	// t_data *current;
	// current = copy.index;
	// while (current != NULL) {
	// 	printf("%d ", current->nb);
	// 	current = current->next;
    // }

    printf("\n");
	// ================================== 

	// frees

	return (EXIT_SUCCESS);
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



// int	*parse_args(int argc, char **argv)
// {
// 	int	i;
// 	int	j;
// 	int	*nbrs;

// 	i = 1;
// 	nbrs = malloc(sizeof(int) * argc - 1);
// 	while (i < argc)
// 	{
// 		j = 0;
// 		if (argv[i][j] == '-')
// 			j++;
// 		while (argv[i][j])
// 		{
// 			if (!ft_isdigit(argv[i][j]))
// 				failure(nbrs);
// 			j++;
// 		}
// 		nbrs[i - 1] = ft_atoi(argv[i]);
// 		i++;
// 	}
// 	return (nbrs);
// }

// void	change_nbrs(int *nbrs, int argc)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < argc)
// 	{
// 		nbrs[i] = i;
// 		i++;
// 	}
// }
