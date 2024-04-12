#include "../include/push_swap.h"

static int	swap(t_data **head)
{
	if (!head || !*head || stack_len(*head) < 2)
		return (0);
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return (1);
}

void	sa(t_data **a, int checker)
{
	if (swap(a) && !checker)
		write(1, "sa\n", 3);
}

void	sb(t_data **b, int checker)
{
	if (swap(b) && !checker)
		write(1, "sb\n", 3);
}

void	ss(t_data **a, t_data **b, int checker)
{
	if (swap(b) && swap(a) && !checker)
		write(1, "sb\n", 3);
}