#include "../../philo.h"

void	test_function()
{
	printf("other function\n");
}
void	*routine(void *real_philo)
{
	t_philo	*fake_philo;

	fake_philo = (t_philo *)real_philo;
	if (fake_philo->id >= 0)
	{
		// printf("id %d next fork %p\n", fake_philo->id, fake_philo->next_mutex);
		// printf("-------\n");
		// printf("id %d next fork %p\n", fake_philo->id, &fake_philo->mutex);
		printf("id %d time to die %d\n", fake_philo->id, fake_philo->tab_to_eat->time_to_die);
	}
	return (NULL);
}
