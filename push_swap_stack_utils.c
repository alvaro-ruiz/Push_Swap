/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:21:42 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/31 14:30:32 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstadd_back(t_stack **lst, int num, int poss)
{
	t_stack *tmp;
	t_stack *new;

	if (!lst)
		return (0);
	new = malloc(sizeof(t_stack));
	if (!new)
        return (0);
    new->num = num;
    new->pos = poss;
    new->cost = 0;
    new->target = NULL;
    new->next = NULL;
    if (!*lst)
    {
        *lst = new;
        return (1);
    }
    tmp = ft_lstlast(*lst);
    if (!tmp)
    {
        free(new);
        return (0);
    }
    tmp->next = new;
    return (1);
}

void	ft_stack_poss(t_stack *lst, int num)
{
	while (lst != NULL)
	{
		lst->pos = lst->pos + num;
		lst = lst->next;
	}
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*ft_lstlast_del(t_stack *lst)
{
	t_stack	*tmp;

	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		if (lst->next->next != NULL)
		{
			tmp = lst->next;
		}
		lst = lst->next;
	}
	return (tmp);
}

int	ft_lstsize(t_stack **lst)
{
	int		i;
	t_stack	*tmp;

	if (!*lst)
		return (0);
	i = 0;
	tmp = *lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void ft_lstclear(t_stack **lst)
{
    t_stack *temp;

    if (!lst || !(*lst))
        return;
        
    while (*lst)
    {
        temp = (*lst)->next;
        free(*lst);
        *lst = temp;
    }
    *lst = NULL;
}