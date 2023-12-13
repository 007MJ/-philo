#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_circle t_circle;

typedef struct s_philo
{
	int				id;
	int				eat;
	int				dead;
	pthread_t		socrate;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*next_mutex;
	t_circle		*tab_to_eat;
}	t_philo;

typedef struct s_circle
{
	int				nb_socrates;
	int				live_time;
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
void		impair_thread(t_philo *philo);
void		pair_thread(t_philo *philo);
void		make_thread(t_circle *tab_rond);
int			main_parsing(char *av[], int ac);
void		eat_after_spleep(t_philo *philo);
int			live_time();
#endif
