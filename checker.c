/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtarza <mtarza@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:13:08 by mtarza            #+#    #+#             */
/*   Updated: 2025/01/28 11:54:24 by mtarza           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_bonus(t_stack_node **stack_a)
{
	t_stack_node	*head;

	head = *stack_a;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

int	checking_moves(t_stack_node **stack_a, t_stack_node **stack_b, char *line)
{
	if (ft_strcmp(line, "pb\n"))
		push_b_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "pa\n"))
		push_a_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "sa\n"))
		swap_a_bonus(stack_a);
	else if (ft_strcmp(line, "sb\n"))
		swap_b_bonus(stack_b);
	else if (ft_strcmp(line, "ss\n"))
		swap_both_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "rb\n"))
		rotate_b_bonus(stack_b);
	else if (ft_strcmp(line, "ra\n"))
		rotate_a_bonus(stack_a);
	else if (ft_strcmp(line, "rr\n"))
		rotate_both_bonus(stack_a, stack_b);
	else if (ft_strcmp(line, "rrb\n"))
		reverse_rotate_b_bonus(stack_b);
	else if (ft_strcmp(line, "rra\n"))
		reverse_rotate_a_bonus(stack_a);
	else if (ft_strcmp(line, "rrr\n"))
		reverse_rotate_both_bonus(stack_a, stack_b);
	else
		return (1);
	return (0);
}

static void	process_moves(t_stack_node **stack_a, t_stack_node **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (checking_moves(stack_a, stack_b, line))
		{
			free(line);
			exit_error(stack_a);
		}
		free(line);
		line = get_next_line(0);
	}
}

static void	validate_and_print_result(t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	if (is_sorted_bonus(stack_a) && lst_size(*stack_b) == 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	handle_input(&stack_a, argv, argc);
	process_moves(&stack_a, &stack_b);
	validate_and_print_result(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
