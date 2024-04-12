#include "../include/push_swap.h"

static int	rotate(t_data **stack)
{
	t_data	*tmp;
	t_data	*last_node;

	if (!stack || !*stack || stack_len(*stack) < 2)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	last_node = find_last_node(*stack);
	last_node->next = tmp;
	last_node->next->prev = last_node;
	return (1);
}

void	ra(t_data **stack_a, int checker)
{
	if (rotate(stack_a) && !checker)
		write(1, "ra\n", 3);
}

void	rb(t_data **stack_b, int checker)
{
	if (rotate(stack_b) && !checker)
		write(1, "rb\n", 3);
}

void	rr(t_data **stack_a, t_data **stack_b, int checker)
{
	if (rotate(stack_b) && rotate(stack_a) && !checker)
		write(1, "rr\n", 3);
}