/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   must_eat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:28:45 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/20 10:45:33 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	must_eat(t_philo *philo)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < philo->tab_to_eat->nb_socrates)
	{
		if (philo->tab_to_eat->tab_socrates[i].eat == philo->tab_to_eat->must_eat)
		{
			j++;
		}
		i++;
	}
	if (j == philo->tab_to_eat->nb_socrates)
	{
		printf("All philo have eat\n");
		philo_print(philo);
		return (-1);
	}
	return (1);
}
