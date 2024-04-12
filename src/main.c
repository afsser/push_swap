#include "../include/push_swap.h"

// void	get_address(t_data *nbrs, t_data *copy)
// {
// 	while (nbrs)
// 	{
// 		copy->index = nbrs;
// 		copy->index->nb = nbrs->nb;
// 		nbrs = nbrs->next;
// 		copy = copy->next;
// 	}
// }
	// t_data	*tmp;
	// t_data	*tmp2;

	// tmp = *nbrs;
	// tmp2 = *copy;

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_data	*nbrs;
	t_data	*curr;

	nbrs = NULL;
	check_args(argc, argv);
	parse_args(argc, argv, &nbrs);
	curr = nbrs;
	replace_with_sequence(nbrs, argc);
	// bubble_sort(&nbrs);
	// ================================== print nbrs

    while (curr) {
        printf("%ld ", curr->nb);
		curr = curr->next;
    }

	free_struct(nbrs);
    printf("\n");
	// ================================== 

	return (EXIT_SUCCESS);
}
