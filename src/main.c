/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 16:35:54 by mnshimiy          #+#    #+#             */
/*   Updated: 2023/12/25 09:22:11 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int ac, char *av[])
{
	t_circle	*tab_rond;

	tab_rond = NULL;
	if (ac == 5 || ac == 6)
	{
		if (main_parsing(av, ac) == -1)
			return (-1);
		tab_rond = create(av);
		if (tab_rond)
		{
			make_thread(tab_rond);
			free_philo(tab_rond);
		}
		else
			return (-1);
	}
	else
		return (-1);
	return (0);
}
