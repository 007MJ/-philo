#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int			id;
	int			*fork;
	int			nb_philo;
	int 		must_eat;
	int			time_to_eat;
	int			time_to_die;
	int			time_to_sleep;
}	t_philo;

void		*routine();
void		create(t_philo *philo);
long	int ft_atoi(char *str);
#endif
