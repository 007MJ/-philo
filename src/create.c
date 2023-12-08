#include "../philo.h"

t_circle	*create(char *av[])
{
	t_circle	*tab_rond;

	tab_rond = ft_calloc(1, sizeof(t_circle));
	if (tab_rond)
	{
		tab_rond->nb_socrates = ft_atoi(av[1]);
		tab_rond->time_to_die = ft_atoi(av[2]);
		tab_rond->time_to_eat = ft_atoi(av[3]);
		tab_rond->time_to_sleep = ft_atoi(av[4]);
		if (ft_atoi(av[5]))
			tab_rond->must_eat = ft_atoi(av[5]);
		else
			tab_rond->must_eat = -1;
	}
	return (tab_rond);
}
