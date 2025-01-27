#include "push_swap.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*prev;
	t_stack_node	*tail;

	prev = NULL;
	tail = *stack;
	if (*stack && (*stack)->next)
	{
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		tail->next = *stack;
		*stack = tail;
	}
}

void	reverse_rotate_a(t_stack_node **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack_node **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	reverse_rotate_both(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr\n", 4);
}
