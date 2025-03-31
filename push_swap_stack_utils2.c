/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:41:29 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/31 14:31:42 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int content, int pos)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->num = content;
	stack->cost = 0;
	stack->target = NULL;
	stack->pos = pos;
	stack->next = NULL;
	return (stack);
}

void	check_rotation(t_stack **a)
{
	t_stack	*smallest;

	smallest = NULL;
	if (!sort(*a))
	{
		smallest = find_smallest(*a);
		if (smallest->pos <= ft_lstsize(a) / 2 + 1)
			while (*a != smallest)
				ra(a);
		else
			while (*a != smallest)
				rra(a);
	}
}

int	sort_a(t_stack **a)
{
	t_stack	*highest_node;

	highest_node = find_highest_node(*a);
	if (*a == highest_node)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(*a);
	return (1);
}

int	sort(t_stack *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	exit_error(t_stack **a, char *argv)
{
	long	num;

	num = 0;
	if (error_syntax(argv))
		return (1);
	num = ft_atoi(argv);
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	if (error_repetition(*a, (int)num))
		return (1);
	return (0);
}
