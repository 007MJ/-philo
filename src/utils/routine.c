#include "../../philo.h"

void	*routine(void *real_philo)
{
	t_philo		*fake_philo;
	long long	time_prog;

	fake_philo = (t_philo *)real_philo;
	time_prog = fake_philo->tab_to_eat->time_prog;
	while (1)
	{
		printf("%lld %d is thinking\n", live_time() - time_prog, fake_philo->id);
		pthread_mutex_lock(&fake_philo->mutex);
		printf("%lld %d has taken a fork\n", live_time() - time_prog , fake_philo->id);
		pthread_mutex_lock(fake_philo->next_mutex);
		printf("%lld %d has taken a fork\n", live_time() - time_prog, fake_philo->id);
		printf("%lld %d is eating\n", live_time() - time_prog, fake_philo->id);
		ft_usleep(fake_philo->tab_to_eat->time_to_die);
		pthread_mutex_unlock(&fake_philo->mutex);
		pthread_mutex_unlock(fake_philo->next_mutex);
		printf("%lld %d is sleeping\n", live_time() - time_prog, fake_philo->id);
		ft_usleep(fake_philo->tab_to_eat->time_to_sleep);
	}
	return (NULL);
}
