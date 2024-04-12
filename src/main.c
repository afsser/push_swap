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

int	success_free(t_data *nbrs)
{
    free_struct(nbrs);
    return(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_data	*stack_a;
	t_data	*stack_b;
	t_data	*curr;

	stack_a = NULL;
	check_args(argc, argv);
	parse_args(argc, argv, &stack_a);
	curr = stack_a;
	replace_with_sequence(stack_a, argc);
	if (!is_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, 0);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		// else if (stack_len(stack_a) == 5)
		// 	sort_five(&stack_a, &stack_b);
		else
			push_swap(&stack_a, &stack_b);
	}
	// bubble_sort(&nbrs);
	// ================================== print nbrs

    while (curr) {
        printf("%ld ", curr->nb);
		curr = curr->next;
    }

	if (stack_b)
		free_struct(stack_b);
	free_struct(stack_a);
    printf("\n");
	// ================================== 

	return (EXIT_SUCCESS);
}
