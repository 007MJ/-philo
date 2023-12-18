/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_after_sleep.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:35:23 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/17 16:28:06 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	eat_after_spleep(t_philo *philo)
{
	printf("%lld %d is eating\n", live_time(), philo->id);
	usleep(philo->tab_to_eat->time_to_die);
	philo->last_eat = live_time();
	pthread_mutex_unlock(&philo->mutex);
	pthread_mutex_unlock(philo->next_mutex);
	printf("%lld %d is sleeping\n", live_time(), philo->id);
	usleep(philo->tab_to_eat->time_to_sleep);
}
