/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:04:11 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/01/07 15:31:07 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	expan_checker(t_circle *tab_rond, int i)
{
	printf("%lld %d died\n", current_time(tab_rond),
		tab_rond->tab_socrates[i].id);
}

void	checker(t_circle *tab_rond)
{
	int			i;
	int			all_eat;

	all_eat = 0;
	while (tab_rond->running == 1)
	{
		i = 0;
		while (i < tab_rond->nb_socrates)
		{
			pthread_mutex_lock(&tab_rond->eat);
			all_eat = must_eat(tab_rond->tab_socrates);
			if ((current_time(tab_rond) - tab_rond->tab_socrates[i].last_eat)
				>= tab_rond->time_to_die || all_eat == -1)
			{
				if (all_eat != -1)
					expan_checker(tab_rond, i);
				tab_rond->running = -1;
				pthread_mutex_unlock(&tab_rond->eat);
				break ;
			}
			pthread_mutex_unlock(&tab_rond->eat);
			i++;
		}
	}
}
