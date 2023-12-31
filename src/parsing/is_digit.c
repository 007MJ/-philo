/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:53:59 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/17 16:33:42 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		while (str[i])
		{
			if ((str[i] >= '0' && str[i] <= '9'))
				i++;
			else
				return (-1);
		}
		return (1);
	}
	return (-1);
}
