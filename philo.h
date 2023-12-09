#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				eat;
	int				dead;
	pthread_t		socrate;
	pthread_mutex_t	mutex;
}	t_philo;

typedef struct s_circle
{
	int				nb_socrates;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	mutex;
	t_philo			*tab_socrates;
}	t_circle;


void		*routine(void *tab_rond);
t_circle	*create(char *av[]);
int			is_digit(char *str);
long	int	ft_atoi(char *str);
void		*ft_calloc(size_t count, size_t size);
void		c_thread(t_circle *tab_rond);
int			main_parsing(char *av[], int ac);
#endif
