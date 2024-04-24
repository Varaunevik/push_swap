/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:26:44 by vaunevik          #+#    #+#             */
/*   Updated: 2024/03/27 14:13:07 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/** Checks whether a stack is already sorted 
 * It iterates through the list and checks whether the 
 * current number is bigger than the next number
**/
int	is_sorted(t_stack **stack)
{
	t_stack	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->number > head->next->number)
			return (0);
		head = head->next;
	}
	return (1);
}

/** This function allocates memory for a new node and
 * stores the content in the node, then setting the
 * next to NULL as this will be the new last node.
**/
t_stack	*ft_stacknew(long content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = content;
	new->next = NULL;
	return (new);
}

t_stack	*ft_stacklast(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (stack != NULL)
	{
		last = stack;
		stack = stack->next;
	}
	return (last);
}

/** This function will add the new node to the end of the linked list **/
void	ft_stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (new == NULL)
		return ;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	last = ft_stacklast(*stack);
	last->next = new;
}
