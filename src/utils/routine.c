#include "../../philo.h"

void	*routine(void *real_philo)
{
	t_philo	*fake_philo;

	fake_philo = (t_philo *)real_philo;
	while (1)
	{
		printf("%lld %d is thinking\n", live_time(), fake_philo->id);
		pthread_mutex_lock(&fake_philo->mutex);
		printf("%lld %d has taken a fork\n", live_time(), fake_philo->id);
		pthread_mutex_lock(fake_philo->next_mutex);
		printf("%lld %d has taken a fork\n", live_time(), fake_philo->id);
		printf("%lld %d is eating\n", live_time(), fake_philo->id);
		usleep(fake_philo->tab_to_eat->time_to_die);
		pthread_mutex_unlock(&fake_philo->mutex);
		pthread_mutex_unlock(fake_philo->next_mutex);
		printf("%lld %d is sleeping\n", live_time(), fake_philo->id);
		usleep(fake_philo->tab_to_eat->time_to_sleep);
	}
	return (NULL);
}
