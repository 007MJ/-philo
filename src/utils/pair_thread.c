/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:28:40 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/17 16:14:50 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	pair_thread(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->mutex);
		printf("%lld %d has taken a fork\n", live_time(), philo->id);
		pthread_mutex_lock(philo->next_mutex);
		printf("%lld %d has taken a fork\n", live_time(), philo->id);
		eat_after_spleep(philo);
	}
}
