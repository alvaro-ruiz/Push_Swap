/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-bl <aruiz-bl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:22:31 by aruiz-bl          #+#    #+#             */
/*   Updated: 2025/03/26 16:32:32 by aruiz-bl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_Stack
{
	long			num;
	int				pos;
	int				cost;
	struct s_Stack	*target;
	struct s_Stack	*next;
}					t_stack;

// Movements
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

// PushSwap
void				move_nodes(t_stack **a, t_stack **b, t_stack *cheapest);
int					push_swap(t_stack *a, t_stack *b);

// Cost
void				ft_cost(t_stack **a, t_stack **b);

// Error
void				free_argv(char **argv);
void				free_stack(t_stack **stack);
int					error_syntax(char *argv);
int					error_repetition(t_stack *a, int nbr);
void				error_free(t_stack **a, char **argv, int argc_2);

// Utils
int					ft_lstadd_back(t_stack **lst, int num, int poss);
void				ft_stack_poss(t_stack *lst, int num);
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*ft_lstlast_del(t_stack *lst);
int					ft_lstsize(t_stack **lst);

// Utils 1
void				set_target(t_stack **a, t_stack **b);
void				ft_find_target(t_stack **a, t_stack **b);
t_stack				*find_smallest(t_stack *stack);
t_stack				*ft_lower_cost(t_stack *stack);
t_stack				*find_highest_node(t_stack *stack);

// Utils 2
t_stack				*ft_stacknew(int content, int pos);
void				check_rotation(t_stack **a);
int					sort_a(t_stack **a);
int					sort(t_stack *a);
int					exit_error(t_stack **a, char *argv);
#endif