#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_symposium
{
	
}	t_symposium;

void		*routine();
void		create(t_philo *philo);
long	int ft_atoi(char *str);
#endif
