/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:11:15 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/22 12:21:17 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

# define LOCK 1
# define UNLOCK 0

typedef struct s_fork
{
	int				pid;
	int				pid_loking;
	int				loking;
}				t_fork;

typedef struct s_philosopher
{
	int			pid;
	int			die;
	int			eat;
	int			sleep;
	pthread_t		thread_philo;
	t_fork		fork;

}				t_philosopher;

typedef struct s_arg
{
	int			number_of_philosophers;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			number_of_times_each_philosopher_must_eat;
	int			timer;
	pthread_mutex_t	lock;
	t_philosopher	*philo;
}				t_arg;

// utils fontion
unsigned int	u_atoi(const char *arg);
// funtion for struct
int				creating_philo(t_arg *arg);
int				die_philo(t_arg *arg, int pid);
int				delete_philo(t_arg *arg);
//acting for the philo
t_arg			*taken_fork(t_arg *arg);

#endif