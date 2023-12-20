/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:06:47 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/20 13:35:48 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long long	current_time(t_philo *philo)
{
	long long	time;

	time = live_time() - philo->tab_to_eat->time_prog;
	return (time);
}

void	if_printf(t_philo *philo, char *str)
{

	pthread_mutex_lock(&philo->tab_to_eat->eat);
	if (philo->tab_to_eat->running == 1)
	{
		printf("%lld %d %s\n", current_time(philo), philo->id, str);
	}
	pthread_mutex_unlock(&philo->tab_to_eat->eat);
}

void	eat_sleep(t_philo *philo)
{
		pthread_mutex_lock(&philo->mutex);
		if_printf(philo, "has taken a fork");
		pthread_mutex_lock(philo->next_mutex);
		if_printf(philo, "has taken a fork");
		if_printf(philo, "is eating");
		ft_usleep(philo->tab_to_eat->time_to_eat);
		pthread_mutex_lock(&philo->tab_to_eat->eat);
		philo->last_eat = current_time(philo);
		philo->eat++;
		pthread_mutex_unlock(&philo->tab_to_eat->eat);
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(philo->next_mutex);
}


void	my_sleep(t_philo *philo)
{
		if_printf(philo, "is sleeping");
		ft_usleep(philo->tab_to_eat->time_to_sleep);
}

void	*routine(void *real_philo)
{
	t_philo		*fake_philo;
	long long	time_prog;

	fake_philo = (t_philo *)real_philo;
	time_prog = fake_philo->tab_to_eat->time_prog;
	while (1)
	{
		pthread_mutex_lock(&fake_philo->tab_to_eat->eat);
		if (fake_philo->tab_to_eat->running == 1)
		{
			pthread_mutex_unlock(&fake_philo->tab_to_eat->eat);
			if_printf(fake_philo, "is thinking");
			eat_sleep(fake_philo);
			my_sleep(fake_philo);
		}
		else
		{
			pthread_mutex_unlock(&fake_philo->tab_to_eat->eat);
			break;
		}

	}
	return (NULL);
}
