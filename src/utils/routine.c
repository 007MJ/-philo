#include "../../philo.h"

void	test_function()
{
	printf("other function\n");
}
void	*routine(void *real_philo)
{
	t_philo	*fake_philo;

	fake_philo = (t_philo *)real_philo;
	return (NULL);
}
