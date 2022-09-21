/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosopher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:22:38 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/21 18:33:37 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	*task(void *p)
{
	printf("creating philo %d\n", *(int *)p);
	return (NULL);
}

int		creating_philo(t_arg *arg)
{
	int	i;
	int	x;

	x = 1;
	i = 0;
	arg->philo = malloc(sizeof(t_philosopher) * arg->number_of_philosophers);
	if (!arg->philo)
		return (1);
	while (i <= arg->number_of_philosophers)
	{
		arg->philo[i].pid = x;
		arg->philo[i].die = UNLOCK;
		pthread_create(&arg->philo[i].thread_philo, NULL, task, &i);
	//	pthread_mutex_init(&arg->philo[i].mutex_philo, NULL);
		i++;
		x++;
	}
	return (0);
}