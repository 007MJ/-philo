/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:28:40 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/01/07 15:33:06 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	philo_print(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->tab_to_eat->eat);
	if (philo->tab_to_eat->running == 1)
	{
		pthread_mutex_lock(&philo->tab_to_eat->mutex);
		printf("%lld %d %s\n", current_time(philo->tab_to_eat), philo->id, str);
		pthread_mutex_unlock(&philo->tab_to_eat->mutex);
	}
	pthread_mutex_unlock(&philo->tab_to_eat->eat);
}
