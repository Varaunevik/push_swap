/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:25:16 by vaunevik          #+#    #+#             */
/*   Updated: 2024/03/28 11:33:54 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/** This function converts the argv into a linked list/stack.
 * It extracts the numbers and converts them to integers.
 * Then it creates a new node which stores the number and adds it to the back.
**/
void	init_stack_a(t_stack **a, char **str)
{
	t_stack	*new;
	int		i;
	long	nbr;

	i = 0;
	while (str[i])
	{
		nbr = ft_atol(str[i]);
		new = ft_stacknew(nbr);
		ft_stackadd_back(a, new);
		i++;
	}
}

/** This function finds the cheapest node by comparing push_cost for each node.
 * It uses the maximum as a starting point for comparison.
**/
void	set_cheapest(t_stack *stack)
{
	long	min;
	t_stack	*cheapest;

	if (stack == NULL)
		return ;
	min = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < min)
		{
			min = stack->push_cost;
			cheapest = stack;
		}
		stack->cheapest = false;
		stack = stack->next;
	}
	cheapest->cheapest = true;
}

/** This function sets the index of each node (its position in the list)
 * It also checks whether the position is under or above the median.
 * This is useful when we are doing our cost analysis later.
**/
void	set_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	median = ft_stacksize(stack) / 2;
	while (stack)
	{
		if (stack != NULL)
		{
			stack->index = i;
			if (i <= median)
				stack->above_median = false;
			else
				stack->above_median = true;
		}
		i++;
		stack = stack->next;
	}
}

/** This function calculates the push cost for each node
 * by doing some simple calculations using the median, length of 
 * list and its current position. 
**/
void	set_push_cost(t_stack *a, t_stack *b)
{
	int	a_length;
	int	b_length;

	a_length = ft_stacksize(a);
	b_length = ft_stacksize(b);
	while (b)
	{
		b->push_cost = b->index;
		if (b->above_median)
			b->push_cost = b_length - (b->index);
		if (b->target->above_median)
			b->push_cost += a_length - (b->target->index);
		else
			b->push_cost += b->target->index;
		b = b->next;
	}
}
