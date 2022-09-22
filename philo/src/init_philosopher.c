/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:22:38 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/22 23:57:07 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	u = 0;

static void	*task(void *p)
{
	t_arg	*arg = (t_arg *)p;
	while (1)
	{

	}
	routine(arg);
	return (NULL);
}

static t_arg	*init_philo(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philosophers)
	{
		arg->philo[i].pid = i + 1;
		arg->philo[i].die = UNLOCK;
		arg->philo[i].eat = UNLOCK;
		arg->philo[i].sleep = UNLOCK;
		arg->philo[i].fork_left = i + 1;
		if (i )
		arg->philo[i].fork_righ = i;
		i++;
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
	pthread_mutex_init(&(arg->talking), NULL);
	arg->lock_fork = malloc(sizeof(pthread_mutex_t) * (arg->number_of_philosophers + 1));
	if (!arg->lock_fork)
		return (1);
	while (i < arg->number_of_philosophers)
	{
		pthread_mutex_init(&(arg->lock_fork[i]), NULL);
		i++;
	}
	i = 0;
	while (i < arg->number_of_philosophers)
	{
		arg->philo[i].arg = arg;
		pthread_create(&arg->philo[i].thread_philo, NULL, task, &arg->philo[i]);
		//sleep(1);
		i++;
	}
	return (0);
}

// int	die_philo(t_arg *arg, int pid)
// {
// 	int	i;

// 	i = 0;
// 	while (arg->philo[i].pid != pid)
// 		i++;
// 	printf("mort %d philo\n", arg->philo[i].pid);
// 	arg->philo[i].die = LOCK;
// 	return (0);
// }

// int	delete_philo(t_arg *arg)
// {
// 	int	i;

// 	i = 0;
// 	while (i < arg->number_of_philosophers)
// 	{
// 		pthread_join(arg->philo[i].thread_philo, NULL);
// 		pthread_mutex_destroy(&arg->philo[i].lock);
// 		pthread_mutex_destroy(&arg->philo[i].fork.lock);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&arg->lock);
// 	free(arg->philo);
// 	return (0);
// }