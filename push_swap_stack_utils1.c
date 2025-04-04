/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:43:24 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/26 15:43:15 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target(t_stack **a, t_stack **b)
{
	t_stack	*a_head;
	t_stack	*b_head;

	a_head = *a;
	b_head = *b;
	while (*b)
	{
		ft_find_target(a, b);
		*b = (*b)->next;
	}
	*a = a_head;
	*b = b_head;
}

void	ft_find_target(t_stack **a, t_stack **b)
{
	t_stack	*target_node;
	t_stack	*a_head;
	int		value;

	value = INT_MAX;
	a_head = *a;
	target_node = NULL;
	while (*a)
	{
		if ((*a)->num <= value && (*b)->num < (*a)->num)
		{
			target_node = *a;
			value = (*a)->num;
		}
		*a = (*a)->next;
	}
	if (INT_MAX == value)
	{
		*a = a_head;
		(*b)->target = find_smallest(*a);
	}
	else
		(*b)->target = target_node;
	*a = a_head;
}

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;

	if (stack == NULL)
		return (NULL);
	smallest = stack;
	while (stack->next)
	{
		if (stack->num < smallest->num)
			smallest = stack;
		stack = stack->next;
	}
	if (stack->num < smallest->num)
		smallest = stack;
	return (smallest);
}

t_stack	*ft_lower_cost(t_stack *stack)
{
	int		costmenor;
	t_stack	*temp;

	if (!stack)
		return (NULL);
	costmenor = stack->cost;
	temp = stack;
	stack = stack->next;
	while (stack)
	{
		if (costmenor > stack->cost)
		{
			temp = stack;
			costmenor = stack->cost;
		}
		stack = stack->next;
	}
	return (temp);
}

t_stack	*find_highest_node(t_stack *stack)
{
	int		highest;
	t_stack	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->num > highest)
		{
			highest = stack->num;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}
