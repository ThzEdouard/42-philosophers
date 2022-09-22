/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:53:58 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/22 23:47:59 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

long int	new_time(struct timeval start, int timer)
{
	struct timeval	end;
	(void) timer;
	gettimeofday(&end, NULL);
	return ((end.tv_usec/1000) - (start.tv_usec/1000));
}

// void	view(t_arg **arg, int pid, int philo, char *action)
// {
// 	if (ft_strcmp(action, "has taken a fork")
// 		&& (*arg)->philo[pid].mutex_lock != LOCK)
// 	{
// 		pthread_mutex_lock(&(*arg)->philo[pid].fork.lock);
// 		(*arg)->philo[pid].mutex_lock = LOCK;
// 	}
// 	printf("%ldms %d %s\n", (*arg)->timer, philo, action);
// 	if (ft_strcmp(action, "is sleeping")
// 		&& (*arg)->philo[pid].mutex_lock != LOCK)
// 	{
// 		pthread_mutex_lock(&(*arg)->philo[pid].fork.lock);
// 		(*arg)->philo[pid].mutex_lock = LOCK;
// 	}
// }