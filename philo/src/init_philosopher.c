/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:22:38 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/22 12:21:23 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	u = 0;

static void	*task(void *p)
{
	t_arg	*arg = (t_arg *)p;
	pthread_mutex_lock(&(arg)->lock);

	pthread_mutex_unlock(&(arg)->lock);
	return (NULL);
}

static t_arg	*init_philo(t_arg *arg, int x)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philosophers)
	{
		arg->philo[i].pid = x;
		arg->philo[i].die = UNLOCK;
		arg->philo[i].fork.pid = x;
		arg->philo[i].fork.pid_loking = UNLOCK;
		arg->philo[i].fork.loking = UNLOCK;
		arg->philo[i].eat = UNLOCK;
		arg->philo[i].sleep = UNLOCK;
		i++;
		x++;
	}

	return (arg);
}

int		creating_philo(t_arg *arg)
{
	int	i;

	i = 0;
	arg->philo = malloc(sizeof(t_philosopher) * (arg->number_of_philosophers + 1));
	if (!arg->philo)
		return (1);
	arg = init_philo(arg, 1);
	pthread_mutex_init(&arg->lock, NULL);
	while (i < arg->number_of_philosophers)
	{
		pthread_create(&arg->philo[i].thread_philo, NULL, task, arg);
		i++;
	}
	return (0);
}

int	die_philo(t_arg *arg, int pid)
{
	int	i;

	i = 0;
	while (arg->philo[i].pid != pid)
		i++;
	printf("mort %d philo\n", arg->philo[i].pid);
	arg->philo[i].die = LOCK;
	arg->philo[i].fork.loking = LOCK;
	return (0);
}

int	delete_philo(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philosophers)
	{
		pthread_join(arg->philo[i].thread_philo, NULL);
		i++;
	}
	pthread_mutex_destroy(&arg->lock);
	free(arg->philo);
	return (0);
}