/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_philosopher.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:29:10 by eflaquet          #+#    #+#             */
/*   Updated: 2022/10/05 13:25:02 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	delete_pthread(t_arg *arg, int i)
{
	int	x;

	x = 0;
	while (x < i)
	{
		pthread_join(arg->philo[x].pthread_philosopher, NULL);
		x++;
	}
}

static void	routine(t_arg *arg, t_philosopher *philosopher)
{
	while (lock_dead(arg))
	{
		eating(philosopher);
		if (!lock_dead(arg))
			break ;
		if (arg->number_of_times_each_philosopher_must_eat != -1)
		{
			if (arg->number_of_times_each_philosopher_must_eat
				== philosopher->nb_eat)
			{
				pthread_mutex_lock(&(arg->eating));
				arg->nb_eat++;
				pthread_mutex_unlock(&(arg->eating));
				break ;
			}
		}
		acting(philosopher->pid, arg, "is sleeping");
		usleep(arg->time_to_sleep * 1000);
		if (!lock_dead(arg))
			break ;
		acting(philosopher->pid, arg, "is thinking");
	}
}

static void	*task(void *p)
{
	t_philosopher	*philosopher;
	t_arg			*arg;

	philosopher = (t_philosopher *)p;
	arg = philosopher->arg;
	if (philosopher->pid % 2)
		usleep(15000);
	if (arg->nb_philosophers == 1)
		solo(philosopher);
	else
		routine(arg, philosopher);
	return (NULL);
}

void	creating_philosopher(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->nb_philosophers)
	{
		if (pthread_create(&(arg->philo[i].pthread_philosopher),
				NULL, task, &arg->philo[i]))
		{
			delete_pthread(arg, i);
			break ;
		}
		i++;
	}
}

void	deleting_philosopher(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->nb_philosophers)
		pthread_join(arg->philo[i++].pthread_philosopher, NULL);
	pthread_mutex_destroy(&(arg->writing));
	pthread_mutex_destroy(&(arg->eating));
	pthread_mutex_destroy(&(arg->dead));
	i = 0;
	while (i < arg->nb_philosophers)
		pthread_mutex_destroy(&(arg->lock_fork[i++]));
}
