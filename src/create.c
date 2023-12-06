#include "../philo.h"

int	*ft_range(int fork)
{
	int	i;
	int	*range;
	i = 1;
	range = malloc(sizeof(int) * fork);
	while (i < fork)
	{
		range[i] = i;
		i++;
	}
	return (range);
}
void	create(t_philo *philo)
{
	int		i;
	t_philo	*current_philo;

	i = 0;
	current_philo = *philo;
	philo->fork = ft_range(philo->nb_philo);
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->socrate[i], NULL, &routine, NULL);
		i++;
	}
	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_join(philo->socrate[i], NULL);
		i++;
	}
}
