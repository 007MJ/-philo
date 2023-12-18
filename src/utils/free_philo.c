/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:14:16 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/17 18:36:28 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	free_philo(t_circle *tab_rond)
{
	int	i;

	i = 0;
	// while (i < tab_rond->nb_socrates)
	// {
	// 	free(&tab_rond->tab_socrates[i]);
	// 	i++;
	// }
	free(tab_rond);
}
