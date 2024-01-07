/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:35:54 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/01/06 15:33:55 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*one_routine(void *real_tab)
{
	t_circle	*fake_tab;

	fake_tab = (t_circle *)real_tab;
	printf("%lld %d is thinking\n",
		current_time(fake_tab), fake_tab->tab_socrates->id);
	printf("%lld %d has taken a fork\n",
		current_time(fake_tab), fake_tab->tab_socrates->id);
	ft_usleep(fake_tab->time_to_die);
	printf("%lld %d died\n", current_time(fake_tab), fake_tab->tab_socrates->id);
	return (NULL);
}

void	one_philo(t_circle *tab_rond)
{
	pthread_mutex_init(&tab_rond->tab_socrates->mutex, NULL);
	tab_rond->tab_socrates->tab_to_eat = tab_rond;
	pthread_create(&tab_rond->tab_socrates->socrate,
		NULL, one_routine, tab_rond);
	pthread_join(tab_rond->tab_socrates->socrate, NULL);
}

int	main(int ac, char *av[])
{
	t_circle	*tab_rond;

	tab_rond = NULL;
	if (ac == 5 || ac == 6)
	{
		if (main_parsing(av, ac) == -1)
			return (-1);
		tab_rond = create(av, ac);
		if (tab_rond)
		{
			if (tab_rond->nb_socrates == 1)
				one_philo(tab_rond);
			make_thread(tab_rond);
			free_philo(tab_rond);
		}
		else
			return (-1);
	}
	else
		return (-1);
	return (0);
}
