/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:37:52 by eflaquet          #+#    #+#             */
/*   Updated: 2022/10/05 14:14:49 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_arg	t_arg;

typedef struct s_philosopher
{
	int				pid;
	int				fork_right;
	int				fork_left;
	long int		time_eating;
	int				nb_eat;
	pthread_mutex_t	eating;
	pthread_t		pthread_philosopher;
	t_arg			*arg;
}				t_philosopher;

typedef struct s_arg
{
	int				nb_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				nb_eat;
	int				i;
	long int		start;
	pthread_mutex_t	dead;
	pthread_mutex_t	*lock_fork;
	pthread_mutex_t	eating;
	pthread_mutex_t	writing;
	t_philosopher	*philo;
}					t_arg;

unsigned int	u_atoi(const char *arg);
long int		get_times(void);
void			free_philosopher(t_arg *arg);
void			creating_philosopher(t_arg *arg);
void			init_philosopher(t_arg *arg, char **argv, int argc);
void			acting(int id, t_arg *arg, char *acting);
int				lock_dead(t_arg *arg);
int				lock_eat(t_arg *arg);
long			lock_time_eating(t_arg *arg, int i );
void			eating(t_philosopher *philo);
void			deleting_philosopher(t_arg *arg);
void			solo(t_philosopher *philo);

#endif