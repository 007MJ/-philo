/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:48:05 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/01/07 15:43:12 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_usleep(long time)
{
	long long	start;

	start = live_time();
	usleep(1000);
	while (live_time() < time + start)
		usleep(150);
}
