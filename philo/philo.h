/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnshimiy <mnshimiy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 21:50:44 by mnshimiy          #+#    #+#             */
/*   Updated: 2024/01/07 15:46:48 by mnshimiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_circle	t_circle;

typedef struct s_philo
{
	int				id;
	long long		last_eat;
	int				dead;
	int				eat;
	int				print;
	pthread_t		socrate;
	pthread_mutex_t	mutex;
	pthread_mutex_t	*next_mutex;
	t_circle		*tab_to_eat;
}	t_philo;

typedef struct s_circle
{
	int						nb_socrates;
	long long				time_prog;
	long long				time_to_die;
	long					time_to_eat;
	long					time_to_sleep;
	int						running;
	int						must_eat;
	pthread_t				spinoza;
	pthread_mutex_t			mutex;
	pthread_mutex_t			eat;
	t_philo					*tab_socrates;
}	t_circle;

void			*routine(void *tab_rond);
t_circle		*create(char *av[], int ac);
int				is_digit(char *str);
long int		ft_atoi(char *str);
void			*ft_calloc(size_t count, size_t size);
int				must_eat(t_philo *philo);
void			make_thread(t_circle *tab_rond);
int				main_parsing(char *av[], int ac);
void			free_philo(t_circle *tab_rond);
void			checker(t_circle *tab_rond);
long long		live_time(void);
long long		current_time(t_circle *tab_rond);
void			ft_usleep(long time);
#endif
