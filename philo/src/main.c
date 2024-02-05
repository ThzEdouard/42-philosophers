/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:44:54 by eflaquet          #+#    #+#             */
/*   Updated: 2022/10/05 14:19:28 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static int	error(char **argv, int argc)
{
	int	i;
	int	x;

	i = 1;
	while (i < argc)
	{
		x = 0;
		while (argv[i][x])
		{
			if (argv[i][x] < 48 || argv[i][x] > 57)
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

static void	check_dead(t_arg *arg)
{
	int	i;

	while (lock_dead(arg) && arg->nb_philosophers > 1)
	{
		i = -1;
		if (lock_eat(arg) == arg->nb_philosophers)
		{
			pthread_mutex_lock(&(arg->dead));
			arg->i = 0;
			pthread_mutex_unlock(&(arg->dead));
			break ;
		}
		while (++i < arg->nb_philosophers && lock_time_eating(arg, i) != 0)
		{
			if (get_times() - lock_time_eating(arg, i) > arg->time_to_die)
			{
				pthread_mutex_lock(&(arg->dead));
				arg->i = 0;
				pthread_mutex_unlock(&(arg->dead));
				acting(arg->philo[i].pid, arg, "died");
				break ;
			}
		}
		usleep(1000);
	}
}

static int	check_arg(char **argv)
{
	if (u_atoi(argv[1]) < 1)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_arg	arg;

	if ((argc == 5 || argc == 6))
	{
		if (!error(argv, argc) && !check_arg(argv))
		{
			printf("use ./philo number_of_philosophers time_to_die "
				"time_to_eat time_to_sleep "
				"[number_of_times_each_philosopher_must_eat]");
			return (0);
		}
		init_philosopher(&arg, argv, argc);
		if (!arg.philo || !arg.lock_fork)
			return (free_philosopher(&arg), 0);
		creating_philosopher(&arg);
		check_dead(&arg);
		deleting_philosopher(&arg);
		free_philosopher(&arg);
	}
	else
		printf("use ./philo number_of_philosophers time_to_die "
			"time_to_eat time_to_sleep "
			"[number_of_times_each_philosopher_must_eat]");
	return (0);
}

long int	get_times(void)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return ((end.tv_sec * 1000) + (end.tv_usec / 1000));
}
