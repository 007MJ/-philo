/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 13:28:17 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/01/07 15:32:26 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	is_dead(t_circle *tab_rond)
{
	pthread_mutex_lock(&tab_rond->eat);
	if (tab_rond->running == -1)
		return (pthread_mutex_unlock(&tab_rond->eat), -1);
	pthread_mutex_unlock(&tab_rond->eat);
	return (1);
}
