/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:06:47 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/17 18:56:55 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	thinking(t_philo *philo, long long time_prog)
{
	if (philo->tab_to_eat->running == 1)
		printf("%lld %d is thinking\n", live_time() - time_prog, philo->id);
}

void	eat_sleep(t_philo *philo, long long time_prog)
{
	pthread_mutex_lock(&philo->tab_to_eat->eat);
	if (philo->tab_to_eat->running == 1)
	{
		pthread_mutex_unlock(&philo->tab_to_eat->eat);
		pthread_mutex_lock(&philo->mutex);
		pthread_mutex_lock(philo->next_mutex);
		if (philo->tab_to_eat->running == 1)
		{
			printf("%lld %d has taken a fork\n", live_time()
				- time_prog, philo->id);
			printf("%lld %d has taken a fork\n", live_time()
				- time_prog, philo->id);
			printf("%lld %d is eating\n", live_time() - time_prog, philo->id);
			ft_usleep(philo->tab_to_eat->time_to_eat);
			pthread_mutex_lock(&philo->tab_to_eat->eat);
		}
		philo->last_eat = live_time() - time_prog;
		philo->eat++;
		pthread_mutex_unlock(&philo->tab_to_eat->eat);
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(philo->next_mutex);
	}
}

void	my_sleep(t_philo *philo, long long time_prog)
{
	if (philo->tab_to_eat->running == 1)
	{
		printf("%lld %d is sleeping\n", live_time() - time_prog, philo->id);
		ft_usleep(philo->tab_to_eat->time_to_sleep);
	}
}

void	*routine(void *real_philo)
{
	t_philo		*fake_philo;
	long long	time_prog;

	fake_philo = (t_philo *)real_philo;
	time_prog = fake_philo->tab_to_eat->time_prog;
	while (fake_philo->tab_to_eat->running == 1)
	{
		thinking(fake_philo, time_prog);
		eat_sleep(fake_philo, time_prog);
		my_sleep(fake_philo, time_prog);
	}
	return (NULL);
}
