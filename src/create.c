/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:36:41 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/17 16:37:02 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_circle	*create(char *av[])
{
	t_circle		*tab_rond;

	tab_rond = NULL;
	tab_rond = ft_calloc(1, sizeof(t_circle));
	if (tab_rond)
	{
		tab_rond->nb_socrates = ft_atoi(av[1]);
		tab_rond->time_to_die = ft_atoi(av[2]);
		tab_rond->time_to_eat = ft_atoi(av[3]);
		tab_rond->time_to_sleep = ft_atoi(av[4]);
		tab_rond->time_prog = live_time();
		pthread_mutex_init(&tab_rond->mutex, NULL);
		pthread_mutex_init(&tab_rond->eat, NULL);
		tab_rond->running = 1;
		if (ft_atoi(av[5]))
			tab_rond->must_eat = ft_atoi(av[5]);
		else
			tab_rond->must_eat = -1;
	}
	return (tab_rond);
}
