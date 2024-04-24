/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:23:28 by vaunevik          #+#    #+#             */
/*   Updated: 2024/03/25 10:25:44 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

void	free_array(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack *stack)
{
	t_stack	*head;
	t_stack	*tmp;

	head = stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
