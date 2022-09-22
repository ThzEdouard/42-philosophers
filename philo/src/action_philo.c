/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:51:50 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/22 12:31:43 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	routine(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->number_of_philosophers)
	{
		if (arg->philo[i].die != LOCK)
		{

		}
		i++;
	}
}

t_arg	*taken_fork(t_arg *arg, int i)
{

	if (i % 2 == 0 && (i + 1) < arg->number_of_philosophers)
	{
		if (arg->philo[i + 1].die != LOCK && arg->philo[i + 1].fork.loking != LOCK && arg->philo[i].fork.loking != LOCK)
		{
			arg->philo[i + 1].fork.pid_loking = arg->philo[i].pid;
			arg->philo[i + 1].fork.loking = LOCK;
		}
	}
	return (arg);
}