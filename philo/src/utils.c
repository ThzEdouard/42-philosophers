/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:08:17 by eflaquet          #+#    #+#             */
/*   Updated: 2022/10/05 11:16:23 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

unsigned int	u_atoi(const char *arg)
{
	unsigned int	x;

	x = 0;
	while ((*arg >= 9 && *arg <= 13) || *arg == 32)
		arg++;
	while (*arg >= 48 && *arg <= 57)
		x = x * 10 + *arg++ - '0';
	return (x);
}

int	lock_dead(t_arg *arg)
{
	int	r;

	pthread_mutex_lock(&(arg->dead));
	r = arg->i;
	pthread_mutex_unlock(&(arg->dead));
	return (r);
}

int	lock_eat(t_arg *arg)
{
	int	r;

	pthread_mutex_lock(&(arg->eating));
	r = arg->nb_eat;
	pthread_mutex_unlock(&(arg->eating));
	return (r);
}

long	lock_time_eating(t_arg *arg, int i)
{
	long	r;

	pthread_mutex_lock(&(arg->eating));
	r = arg->philo[i].time_eating;
	pthread_mutex_unlock(&(arg->eating));
	return (r);
}
