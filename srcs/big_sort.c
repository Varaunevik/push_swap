/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:15:09 by vaunevik          #+#    #+#             */
/*   Updated: 2024/03/27 14:05:59 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/** This is our main sorting algorithm;
 * It pushes the nodes from a to b until only 3 nodes left in stack a.
 * It then initiates b stack and pushes the nodes back to a again.
 * Then we updates the indices in a and make sure the min is at the top.
**/
void	big_sort(t_stack **a, t_stack **b)
{
	while (ft_stacksize(*a) > 3)
		pb(a, b);
	sort3(a);
	while (*b)
	{
		init_stack_b(a, b);
		b_to_a(a, b);
	}
	set_index(*a);
	min_to_top(a);
}
