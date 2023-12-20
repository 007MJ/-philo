/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:04:11 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/20 13:38:00 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	checker(t_circle *tab_rond)
{
	int			i;
	int			all_eat;
	long long	time;

	time = 0;
	all_eat = 0;
	while (tab_rond->running == 1)
	{
		i = 0;
		while (i < tab_rond->nb_socrates)
		{
			time = live_time() - tab_rond->time_prog;
			pthread_mutex_lock(&tab_rond->eat);
			all_eat = must_eat(tab_rond->tab_socrates);
			if ((time - tab_rond->tab_socrates[i].last_eat)
				>= tab_rond->time_to_die || all_eat == -1)
			{
				if (all_eat != -1)
					printf("%lld %d died\n", time, tab_rond->tab_socrates[i].id);
				tab_rond->running = -1;
				pthread_mutex_unlock(&tab_rond->eat);
				break;
			}
			else
				pthread_mutex_unlock(&tab_rond->eat);
			i++;
		}
	}
}
