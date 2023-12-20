/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:28:40 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/20 10:11:27 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_print(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->tab_to_eat->nb_socrates)
	{
		philo->tab_to_eat->tab_socrates[i].print = -1;
		i++;
	}
}
