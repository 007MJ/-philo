/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:41:59 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/07 15:52:51 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	ft_bzero(void *ptr, size_t size)
{
	unsigned char *c;
	size_t	i;

	i = 0;
	c = (unsigned char *)ptr;
	while (i < size)
	{
		c[i] = 0;
		i++;
	}
}
void	*ft_calloc(size_t count, size_t size)
{
	char *ptr;
	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ptr = malloc(count * size);
	ft_bzero(ptr, size);
	return (ptr);
}
