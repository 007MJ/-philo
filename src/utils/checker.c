/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:04:11 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/19 20:54:00 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"
// faire une function qui regarde si tout le monde a manage
void	checker(t_circle *tab_rond)
{
	int			i;
	long long	time;

	time = 0;
	while (tab_rond->running == 1)
	{
		i = 0;
		while (i < tab_rond->nb_socrates && tab_rond->running == 1)
		{
			time = live_time();
			pthread_mutex_lock(&tab_rond->eat);
			if (((time - tab_rond->time_prog)
					- tab_rond->tab_socrates[i].last_eat)
				>= tab_rond->time_to_die)
			{
				printf("%lld %d died\n", time - tab_rond->time_prog,
					tab_rond->tab_socrates[i].id);
				tab_rond->running = -1;
				pthread_mutex_unlock(&tab_rond->eat);
			}
			else
				pthread_mutex_unlock(&tab_rond->eat);

			i++;
		}
	}
}
