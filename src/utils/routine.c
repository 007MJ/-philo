#include "../../philo.h"

void	test_function()
{
	printf("other function\n");
}
void	*routine(void *tab_rond)
{
	t_circle	*same_tab;

	same_tab = (t_circle *)tab_rond;
	pthread_mutex_lock(&same_tab->tab_socrates->mutex);
	for (int i = 0; i < 100; i++)
		printf("---%d\n", i);
	pthread_mutex_unlock(&same_tab->tab_socrates->mutex);
	return (NULL);
}
