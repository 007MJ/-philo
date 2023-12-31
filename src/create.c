/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 18:34:54 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/01/07 14:57:20 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_input(t_circle *tab_rond)
{
	if (tab_rond->time_to_die < 60)
		return (-1);
	if (tab_rond->time_to_eat < 60)
		return (-1);
	if (tab_rond->time_to_sleep < 60)
		return (-1);
	if (tab_rond->nb_socrates > 200)
		return (-1);
	return (1);
}

int	expan_creater(t_circle *tab_rond, char *av[], int ac)
{
	if (ft_atoi(av[5]) && ac == 6)
	{
		if (ft_atoi(av[5]) <= 0)
			return (-1);
		else
			tab_rond->must_eat = ft_atoi(av[5]);
		return (1);
	}
	tab_rond->must_eat = -1;
	return (1);
}

t_circle	*create(char *av[], int ac)
{
	t_circle	*tab_rond;

	tab_rond = ft_calloc(1, sizeof(t_circle));
	if (tab_rond)
	{
		tab_rond->nb_socrates = ft_atoi(av[1]);
		tab_rond->time_to_die = ft_atoi(av[2]);
		tab_rond->time_to_eat = ft_atoi(av[3]);
		tab_rond->time_to_sleep = ft_atoi(av[4]);
		tab_rond->tab_socrates = ft_calloc(tab_rond->nb_socrates,
				sizeof(t_philo));
		tab_rond->time_prog = live_time();
		pthread_mutex_init(&tab_rond->mutex, NULL);
		pthread_mutex_init(&tab_rond->eat, NULL);
		tab_rond->running = 1;
		if (expan_creater(tab_rond, av, ac) == -1)
			return (NULL);
		if (check_input(tab_rond) == -1)
			return (NULL);
	}
	return (tab_rond);
}
