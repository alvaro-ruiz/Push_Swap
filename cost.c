/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcularcoste.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:55:23 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/26 15:47:32 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		len_a;
	int		len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	tmp_b = *b;
	while (*b)
	{
		(*b)->cost = (*b)->pos;
		if ((*b)->pos > len_b / 2)
			(*b)->cost = len_b - ((*b)->pos);
		if ((*b)->target->pos > len_a / 2)
			(*b)->cost += len_a - ((*b)->target->pos);
		else
			(*b)->cost += (*b)->target->pos;
		*b = (*b)->next;
	}
	*b = tmp_b;
}
