/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:07:19 by vaunevik          #+#    #+#             */
/*   Updated: 2024/03/27 11:58:36 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!*a)
		return ;
	node = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = node;
}

/**
 * Pushing the head node of b to the top of a
**/
void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_printf("pa\n");
}

/**
 * Pushing the head node of a to the top of b
**/
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_printf("pb\n");
}
