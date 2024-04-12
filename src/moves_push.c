#include "../include/push_swap.h"

static int	push_move(t_data **src, t_data **dest)
{
	t_data	*tmp;

	if (!src || !*src)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
	(*dest)->prev = NULL;
	return (1);
}

void	pa(t_data **stack_b, t_data **stack_a, int checker)
{
	if (push_move(stack_b, stack_a) && !checker)
		write(1, "pa\n", 3);
}

void	pb(t_data **stack_a, t_data **stack_b, int checker)
{
	if (push_move(stack_a, stack_b) && !checker)
		write(1, "pb\n", 3);
}