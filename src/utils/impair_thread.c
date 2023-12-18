/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impair_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:28:45 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/17 16:19:25 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	impair_thread(t_philo *philo)
{
	pthread_mutex_lock(&philo->mutex);
	printf("%lld %d has taken a fork\n", live_time(), philo->id);
	pthread_mutex_lock(philo->next_mutex);
	printf("%lld %d has taken a fork\n", live_time(), philo->id);
	eat_after_spleep(philo);
}
