/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:11:15 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/22 23:54:07 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

# define LOCK 1
# define UNLOCK 0

typedef struct s_arg	t_arg;

typedef struct s_philosopher
{
	int			pid;
	int			die;
	int			eat;
	int			sleep;
	int			fork_righ;
	int			fork_left;
	pthread_t		thread_philo;
	int				mutex_lock;
	t_arg		*arg;
}				t_philosopher;

typedef struct s_arg
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	struct timeval	start;
	long int	timer;
	pthread_mutex_t	talking;
	pthread_mutex_t	*lock_fork;
	t_philosopher	*philo;
}				t_arg;

// utils fontion
unsigned int	u_atoi(const char *arg);
int	ft_strcmp(char *s1, char *s2);
// funtion for struct
int				creating_philo(t_arg *arg);
int				die_philo(t_arg *arg, int pid);
int				delete_philo(t_arg *arg);
//acting for the philo
t_arg			*taken_fork(t_arg *arg, int i);
t_arg	*eating(t_arg *arg, int i);
t_arg	*sleeping(t_arg *arg, int i);
void	view(t_arg **arg, int pid, int philo, char *action);
long int	new_time(struct timeval	start, int timer);
void	routine(t_arg *arg);
#endif