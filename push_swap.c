/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:19:18 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/26 15:50:37 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_stack *a, t_stack *b)
{
	while (ft_lstsize(&a) > 3)
		pb(&a, &b);
	sort_a(&a);
	while (ft_lstsize(&b) > 0)
	{
		set_target(&a, &b);
		ft_cost(&a, &b);
		move_nodes(&a, &b, ft_lower_cost(b));
		pa(&a, &b);
	}
	check_rotation(&a);
	return (0);
}

static void	do_rr(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
}

static void	do_rrr(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->pos <= ft_lstsize(stack) / 2 + 1)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->pos <= ft_lstsize(stack) / 2 + 1)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	move_nodes(t_stack **a, t_stack **b, t_stack *cheapest)
{
	if (cheapest->pos <= ft_lstsize(b) / 2
		&& cheapest->target->pos > ft_lstsize(a) / 2)
		do_rr(a, b, cheapest);
	else if (cheapest->pos > ft_lstsize(b) / 2
		&& cheapest->target->pos <= ft_lstsize(a) / 2)
		do_rrr(a, b, cheapest);
	finish_rotation(b, cheapest, 'b');
	finish_rotation(a, cheapest->target, 'a');
}
