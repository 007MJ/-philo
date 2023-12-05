#include "../philo.h"


int main(int ac, char *av[])
{

	if (ac > 1)
	{
		t_philo	**philo;

		philo = malloc(sizeof(t_philo));
		(*philo)->nb_philo = (int)ft_atoi(av[1]);
		// philo->time_to_die = ft_atoi(av[2]);
		// philo->time_to_eat = ft_atoi(av[3]);
		// philo->time_to_sleep = ft_atoi(av[4]);
		// philo->must_eat = ft_atoi(av[5]);
		create(philo);
	}
}
