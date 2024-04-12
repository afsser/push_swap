#include "../include/push_swap.h"

static int	reverse_rotate(t_data **stack)
{
	t_data	*tmp;
	t_data	*last_node;

	if (!stack || !*stack || stack_len(*stack) < 2)
		return (0);
	last_node = find_last_node(*stack);
	tmp = last_node;
	last_node = last_node->prev;
	last_node->next = NULL;
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = tmp;
	return (1);
}

void	rra(t_data **stack_a, int checker)
{
	if (reverse_rotate(stack_a) && !checker)
		write(1, "rra\n", 4);
}

void	rrb(t_data **stack_b, int checker)
{
	if (reverse_rotate(stack_b) && !checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_data **stack_a, t_data **stack_b, int checker)
{
	if (reverse_rotate(stack_b) && reverse_rotate(stack_a) && !checker)
		write(1, "rrr\n", 4);
}