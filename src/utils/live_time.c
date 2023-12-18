/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:13:01 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/17 16:19:00 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

long long	live_time(void)
{
	struct timeval	start;

	if (gettimeofday(&start, NULL) == -1)
		return (printf("Error time"), -1);
	return ((start.tv_sec * 1000) + (start.tv_usec / 1000));
}
