#include "../include/push_swap.h"

int	stack_len(t_data *stack)
{
	t_data	*current;
	int		count;

	count = 0;
	current = stack;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}

t_data	*find_last_node(t_data *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_data	*get_max(t_data *stack)
{
	int		max;
	t_data	*temp;

	temp = stack;
	max = stack->nb;
	while (stack)
	{
		if (stack->nb > max)
			max = stack->nb;
		stack = stack->next;
	}
	while (temp)
	{
		if (temp->nb == max)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

t_data	*get_min(t_data *stack)
{
	int		min;
	t_data	*temp;

	temp = stack;
	min = stack->nb;
	while (stack)
	{
		if (stack->nb < min)
			min = stack->nb;
		stack = stack->next;
	}
	while (temp)
	{
		if (temp->nb == min)
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

int	is_sorted(t_data *stack)
{
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}