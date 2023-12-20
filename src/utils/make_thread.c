/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:15:27 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/20 08:47:51 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	init_mutex(t_philo *philo, int nb_socrate)
{
	int	i;

	i = 0;
	while (i < nb_socrate)
	{
		pthread_mutex_init(&philo[i].mutex, NULL);
		philo[i].id = i;
		philo[i].next_mutex = &philo[(i + 1) % nb_socrate].mutex;
		i++;
	}
}

void	init_philo(t_philo *philo, int nb_socrate)
{
	int	i;

	i = 0;
	while (i < nb_socrate)
	{
		philo[i].dead = 0;
		philo[i].eat = 0;
		i++;
	}
}

void	make_thread(t_circle	*tab_rond)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = tab_rond->tab_socrates;
	init_mutex(philo, tab_rond->nb_socrates);
	init_philo(philo, tab_rond->nb_socrates);
	while (i < tab_rond->nb_socrates && philo != NULL)
	{
		philo[i].tab_to_eat = tab_rond;
		pthread_create(&philo[i].socrate, NULL, routine, &philo[i]);
		i++;
	}
	checker(tab_rond);
	i = 0;
	while (i < tab_rond->nb_socrates && philo != NULL)
	{
		pthread_join(philo[i].socrate, NULL);
		i++;
	}
}
