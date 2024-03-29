/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_both.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:07:30 by vaunevik          #+#    #+#             */
/*   Updated: 2024/03/27 13:54:58 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *target)
{
	while (*a != target->target && *b != target)
		rr(a, b);
	set_index(*a);
	set_index(*b);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *target)
{
	while (*a != target->target && *b != target)
		rrr(a, b);
	set_index(*a);
	set_index(*b);
}

void	target_top_a(t_stack **a, t_stack *target)
{
	while (*a != target)
	{
		if (target->above_median)
			rra(a);
		else
			ra(a);
	}
}

void	target_top_b(t_stack **b, t_stack *target)
{
	while (*b != target)
	{
		if (target->above_median)
			rrb(b);
		else
			rb(b);
	}
}

void	min_to_top(t_stack **a)
{
	t_stack	*min;

	min = find_min(*a);
	if (min->above_median == 0)
	{
		while (*a != min)
			ra(a);
	}
	else
	{
		while (*a != min)
			rra(a);
	}
}
