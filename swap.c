/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:07:48 by vaunevik          #+#    #+#             */
/*   Updated: 2024/03/27 12:00:27 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../includes/push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	tmp = second->next;
	*a = second;
	second->next = first;
	first->next = tmp;
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	tmp = second->next;
	*b = second;
	second->next = first;
	first->next = tmp;
	ft_printf("sb\n");
}
