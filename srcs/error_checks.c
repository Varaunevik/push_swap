/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaunevik <vaunevik@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 09:50:17 by vaunevik          #+#    #+#             */
/*   Updated: 2024/03/28 11:32:29 by vaunevik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

/**
 * This function checks for duplicates by iterating through 
 * our linked list and updating a counter anytime a number 
 * matches the tmp list (comparing against itself)
**/
int	check_duplicates(t_stack *a)
{
	t_stack	*tmp;
	int		check;

	check = 0;
	while (a != NULL)
	{
		tmp = a;
		check = 0;
		while (tmp != NULL)
		{
			if (tmp->number == a->number)
				check++;
			tmp = tmp->next;
		}
		if (check > 1)
			return (1);
		a = a->next;
	}
	return (0);
}

/** This function checks whether the input string only contains
 * valid characters (signs or numbers), and no other unwanted chars.
**/
int	is_number(const char *str)
{
	if ((*str) == '\0')
		return (0);
	if ((*str) == '+' || (*str) == '-')
	{
		if (ft_strlen(str) == 1)
			return (0);
		str++;
	}
	while (*str)
	{
		if ((*str) < '0' || (*str) > '9')
			return (0);
		str++;
	}
	return (1);
}

/** This function checks whether the 
 * current number is less than the maximum integer
**/
int	valid_int(char *s)
{
	long	nbr;

	nbr = ft_atol(s);
	if (nbr >= INT_MIN && nbr <= INT_MAX)
		return (1);
	return (0);
}

/** This function is the main checker function and calls
 * the corresponding functions to fully validate the input string.
**/
int	check_input(t_stack **a, const char *str)
{
	int		i;
	char	**tmp;

	i = 0;
	if (*str == '\0')
		return (0);
	tmp = ft_split(str, ' ');
	while (tmp[i] != NULL)
	{
		if (!is_number(tmp[i]) || !valid_int(tmp[i]))
		{
			free_array(tmp);
			return (0);
		}
		i++;
	}
	init_stack_a(a, tmp);
	if (check_duplicates(*a))
	{
		free_array(tmp);
		free_stack(*a);
		return (0);
	}
	free_array(tmp);
	return (1);
}
