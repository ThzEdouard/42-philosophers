/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acting_philosopher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:18:18 by eflaquet          #+#    #+#             */
/*   Updated: 2022/10/06 10:32:30 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static int	taking_fork(t_philosopher *philo)
{
	t_arg	*arg;

	arg = philo->arg;
	if ((philo->pid - 1) % 2)
	{
		pthread_mutex_lock(&(arg->lock_fork[philo->fork_left]));
		if (!lock_dead(arg))
			return (pthread_mutex_unlock(&(arg->lock_fork[philo->fork_left]))
				, 0);
		acting(philo->pid, arg, "has taken a fork");
		pthread_mutex_lock(&(arg->lock_fork[philo->fork_right]));
		acting(philo->pid, arg, "has taken a fork");
	}
	else
	{
		usleep(500);
		pthread_mutex_lock(&(arg->lock_fork[philo->fork_right]));
		if (!lock_dead(arg))
			return (pthread_mutex_unlock(&(arg->lock_fork[philo->fork_right]))
				, 0);
		acting(philo->pid, arg, "has taken a fork");
		pthread_mutex_lock(&(arg->lock_fork[philo->fork_left]));
		acting(philo->pid, arg, "has taken a fork");
	}
	return (1);
}

void	eating(t_philosopher *philo)
{
	t_arg	*arg;

	arg = philo->arg;
	if (!taking_fork(philo))
		return ;
	pthread_mutex_lock(&(arg->eating));
	acting(philo->pid, arg, "is eating");
	philo->nb_eat++;
	philo->time_eating = get_times();
	pthread_mutex_unlock(&(arg->eating));
	usleep(arg->time_to_eat * 1000);
	pthread_mutex_unlock(&(arg->lock_fork[philo->fork_left]));
	pthread_mutex_unlock(&(arg->lock_fork[philo->fork_right]));
}

void	acting(int id, t_arg *arg, char *acting)
{
	long int	time;

	time = get_times() - arg->start;
	pthread_mutex_lock(&(arg->writing));
	printf("%ld %d %s\n", time, id, acting);
	pthread_mutex_unlock(&(arg->writing));
}

void	solo(t_philosopher *philo)
{
	t_arg		*arg;
	long int	i;

	arg = philo->arg;
	i = get_times();
	pthread_mutex_lock(&(arg->lock_fork[philo->fork_left]));
	acting(philo->pid, arg, "has taken a fork");
	pthread_mutex_unlock(&(arg->lock_fork[philo->fork_left]));
	usleep(arg->time_to_die * 1000);
	pthread_mutex_lock(&(arg->dead));
	arg->i = 0;
	pthread_mutex_unlock(&(arg->dead));
	acting(philo->pid, arg, "dead");
}
