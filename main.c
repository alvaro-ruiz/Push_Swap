/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:13:38 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/27 13:51:23 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void next(t_stack **a, t_stack **b)
{
	if (!sort(*a))
	{
		if (ft_lstsize(a) == 2)
			sa(*a);
		else if (ft_lstsize(a) == 3)
			sort_a(a);
		else
			push_swap(*a, *b);
	}
}

t_stack	*complete_stack(char **argv, int argc)
{
	t_stack	*a;
	int		i;
	int		ok;

	i = 1;
	a = ft_stacknew(ft_atoi(argv[0]), 0);
	if (argc == 2)
		argc = 1;
	else
		argc = 0;
	while (argv[i])
	{
		if (exit_error(&a, argv[i]))
			error_free (&a, argv, argc);
		ok = ft_lstadd_back(&a, ft_atoi(argv[i]), i - 1);
		if (!ok)
		{
			free_stack(&a);
			return (NULL);
		}
		i++;
	}
	if (argc == 2)
		free_argv(argv);
	return (a);
}

t_stack	*complete_stack_2(char **argv, int argc)
{
	t_stack	*a;
	int		i;
	int		ok;

	i = 2;
	a = ft_stacknew(ft_atoi(argv[1]), 0);
	if (argc == 2)
		argc = 1;
	else
		argc = 0;
	while (argv[i])
	{
		if (exit_error(&a, argv[i]))
			error_free (&a, argv, argc);
		ok = ft_lstadd_back(&a, ft_atoi(argv[i]), i - 1);
		if (!ok)
		{
			free_stack(&a);
			return (NULL);
		}
		i++;
	}
	if (argc == 2)
		free_argv(argv);
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char **split;

	a = NULL;
	b = NULL;
	split = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (!split)
			return (0);
		a = complete_stack(split, argc);
	}
	else
		a = complete_stack_2(argv, argc);
	next(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
