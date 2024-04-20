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
	// t_data	*stack_b;

	t_data	*curr;

	stack_a = NULL;

	check_args(argc, argv);
	create_stack(argc, argv, &stack_a);
	replace_with_sequence(stack_a, argc);
	curr = stack_a;

	// if (!is_sorted(stack_a))
	// {
		// if (stack_len(stack_a) == 2)
			// sa(&stack_a, 0);
		// else if (stack_len(stack_a) == 3)
			// sort_three(&stack_a);
		// else if (stack_len(stack_a) == 5)
		// 	sort_five(&stack_a, &stack_b);
		// else
			// push_swap(&stack_a, &stack_b);
	// }

	// ================================== print nbrs
    while (curr) {
        printf("%d ", curr->nb);
		curr = curr->next;
    }


	// stack_a = stack_a->next;
	// stack_a = stack_a->next;
	// stack_a = stack_a->next;
	// stack_a = stack_a->next;
	// printf("\n%d\n", stack_a->prev->nb);
	// printf("\n");

	// t_data *last_node = find_last_node(stack_a);
	// while (last_node) {
	// 	printf("%d ", last_node->index);
	// 	last_node = last_node->prev;
	// }


	// printf("\n");
	// while (i < 0)
	// {
	// 	printf("%d ", stack_a->index);
	// 	stack_a = stack_a->prev;
	// 	i--;
	// }

	// ================================== 
	free_struct(stack_a);
	// if (stack_b)
		// free_struct(stack_b);
    printf("\n");

	return (EXIT_SUCCESS);
}
