#include "../../philo.h"

void	*routine(void *real_philo)
{
	t_philo	*fake_philo;
	int		running;

	fake_philo = (t_philo *)real_philo;
	running = 1;
	while (running == 1)
	{
		impair_thread(fake_philo);
		running++;
	}
	return (NULL);
}
