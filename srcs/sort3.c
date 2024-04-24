/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:47:40 by vaunevik          #+#    #+#             */
/*   Updated: 2024/03/25 14:47:51 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/** This function finds the max node in the list and returns a pointer to it
 * It does so by first assigning the min long value to the max, ensuring
 * no node->number will be lower and then proceeds to iterate, updating
 * whenever a larger number is found.
**/
t_stack	*find_max(t_stack *stack)
{
	long	max;
	t_stack	*max_node;

	if (stack == NULL)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->number > max)
		{
			max = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

/** This function will sort three nodes in ascending order
 * It finds the node w. max value and compares it to the first and second. 
 * If the node head is still bigger than the 2nd, we perform a swap.
**/
void	sort3(t_stack **stack)
{
	t_stack	*max;

	if (is_sorted(stack))
		return ;
	max = find_max(*stack);
	if (*stack == max)
		ra(stack);
	else if ((*stack)->next == max)
		rra(stack);
	if (((*stack)->number) > ((*stack)->next->number))
		sa(stack);
}
