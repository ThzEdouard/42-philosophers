/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:22:38 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/21 19:18:11 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	*task(void *p)
{
	t_philosopher t = *(t_philosopher *)p;
	printf("creating philo %d\n", t.pid);
	return (NULL);
}

int		creating_philo(t_arg *arg)
{
	int	i;
	int	x;

	x = 1;
	i = 0;
	arg->philo = malloc(sizeof(t_philosopher) * (arg->number_of_philosophers + 1));
	if (!arg->philo)
		return (1);
	while (arg->number_of_philosophers)
	{
		arg->philo[i].pid = x;
		arg->philo[i].die = UNLOCK;
		pthread_mutex_init(&arg->philo[i].mutex_philo, NULL);
		pthread_create(&arg->philo[i].thread_philo, NULL, task, &arg->philo[i]);
		pthread_detach(arg->philo[i].thread_philo);
		arg->number_of_philosophers--;
		x++;
	}
	return (0);
}