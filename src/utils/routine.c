#include "../../philo.h"

void	test_function()
{
	printf("other function\n");
}
void	*routine(void *real_philo)
{
	t_philo	*fake_philo;

	fake_philo = (t_philo *)real_philo;
	// if (fake_philo->id % 2 == 0)
	// {
		printf("id %d next fork %d\n", fake_philo->id, fake_philo->next_mutex_id);
	// }
	return (NULL);
}
