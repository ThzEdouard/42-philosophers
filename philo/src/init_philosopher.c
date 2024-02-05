/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:01:39 by eflaquet          #+#    #+#             */
/*   Updated: 2022/10/05 11:48:02 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	malloc_fork(t_arg **arg, int size)
{
	int	i;

	i = 0;
	(*arg)->lock_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* (size + 1));
	if (!(*arg)->lock_fork)
		return ;
	while (i < (*arg)->nb_philosophers)
	{
		pthread_mutex_init(&((*arg)->lock_fork[i]), NULL);
		i++;
	}
}

static void	malloc_philosopher(t_arg **arg, int size)
{
	int	i;

	i = 0;
	(*arg)->philo = (t_philosopher *) malloc(sizeof(t_philosopher)
			* (size + 1));
	if (!(*arg)->philo)
		return ;
	while (i < (*arg)->nb_philosophers)
	{
		(*arg)->philo[i].pid = i + 1;
		(*arg)->philo[i].fork_left = i;
		(*arg)->philo[i].fork_right = (i + 1) % (*arg)->nb_philosophers;
		(*arg)->philo[i].arg = (*arg);
		(*arg)->philo[i].nb_eat = 0;
		(*arg)->philo[i].time_eating = 0;
		pthread_mutex_init(&((*arg)->philo[i].eating), NULL);
		i++;
	}
}

void	init_philosopher(t_arg *arg, char **argv, int argc)
{
	arg->nb_philosophers = u_atoi(argv[1]);
	arg->time_to_die = u_atoi(argv[2]);
	arg->time_to_eat = u_atoi(argv[3]);
	arg->time_to_sleep = u_atoi(argv[4]);
	arg->i = 1;
	arg->start = get_times();
	arg->number_of_times_each_philosopher_must_eat = -1;
	arg->nb_eat = 0;
	if (argc == 6)
		arg->number_of_times_each_philosopher_must_eat = u_atoi(argv[5]);
	arg->philo = NULL;
	arg->lock_fork = NULL;
	pthread_mutex_init(&(arg->writing), NULL);
	pthread_mutex_init(&(arg->eating), NULL);
	pthread_mutex_init(&(arg->dead), NULL);
	malloc_philosopher(&arg, arg->nb_philosophers);
	malloc_fork(&arg, arg->nb_philosophers);
}

void	free_philosopher(t_arg *arg)
{
	if (arg->philo)
		free(arg->philo);
	if (arg->lock_fork)
		free(arg->lock_fork);
}
