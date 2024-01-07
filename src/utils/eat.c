/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:35:23 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/01/07 15:31:34 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	philo_print(philo, "has taken a fork");
	pthread_mutex_lock(philo->next_mutex);
	philo_print(philo, "has taken a fork");
}

void	off_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(philo->next_mutex);
}

int	eat(t_philo *philo)
{
	if (is_dead(philo->tab_to_eat) == -1)
		return (-1);
	take_fork(philo);
	philo_print(philo, "is eating");
	ft_usleep(philo->tab_to_eat->time_to_eat);
	pthread_mutex_lock(&philo->tab_to_eat->eat);
	philo->last_eat = current_time(philo->tab_to_eat);
	philo->eat++;
	pthread_mutex_unlock(&philo->tab_to_eat->eat);
	off_fork(philo);
	if (is_dead(philo->tab_to_eat) == -1)
		return (-1);
	return (1);
}
