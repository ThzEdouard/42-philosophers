/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 22:51:50 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/22 23:53:08 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

//voir pour recursif routine help ??

// void	test_routine(t_arg *arg, int i, int x, int i_lock)
// {
// 	if (i + 1 > i_lock || i - 1 < 0)
// 		i = i_lock / 2;

// 	if (/*add test mort d'un philo*/arg->philo[i].die != LOCK)
// 	{

// 	}
// 	else
// 		return ;
// 	test_routine(arg, i + 1, x, i_lock);
// 	test_routine(arg, i - 1, x, i_lock);
// }

void	taken_fork(t_philosopher *philo)
{
	if (philo->pid % 2)
		philo->arg->
}

// void	routine(t_arg *arg)
// {
// 	int	i;
// 	int	x;

// 	i = 0;
// 	x = 0;
// 	// pthread_mutex_lock(&arg->lock);
// 	while (1)
// 	{
// 	//	printf("x = %d i = %d\n", x, i);
// 		if (i < 0)
// 			i = 0;
// 		pthread_mutex_lock(&arg->philo[i].lock);
// 		if (arg->philo[i].die != LOCK)
// 		{
// 			arg = recusif_taken_fork(arg, arg->philo[i].pid,i);
// 			arg = eating(arg, i);
// 			usleep(arg->time_to_eat*1000);
// 			arg = sleeping(arg, i);
// 			usleep(arg->time_to_sleep*1000);
// 		}
// 		printf("i = %d x = %d\n", i, x);
// 		pthread_mutex_unlock(&arg->philo[i].lock);
// 		if (x == 0)
// 			i++;
// 		else
// 			i--;
// 		if (i == arg->number_of_philosophers)
// 			x++;
// 		else if (i < 0)
// 			x--;

// 	}
// 	//pthread_mutex_unlock(&arg->lock);
// }

// t_arg	*eating(t_arg *arg, int i)
// {
// 	if (arg->philo->eat == LOCK)
// 	{
// 		arg->philo[i].sleep = LOCK;
// 		printf("%ldms %d  is eating\n", arg->timer, arg->philo[i].pid);
// 	}
// 	return (arg);
// }

// t_arg	*sleeping(t_arg *arg, int i)
// {

// 	arg->timer = new_time(arg->start,arg->timer);
// 	if (arg->philo[i].sleep == LOCK)
// 	{
// 			arg->philo[i].fork.loking = UNLOCK;
// 			arg->philo[i + 1].fork.loking = UNLOCK;
// 			arg->philo[i - 1].fork.loking = UNLOCK;
// 			arg->philo[i].nb_fork = 0;
// 			printf("%ldms %d is sleeping\n", arg->timer,arg->philo[i].pid);
// 			pthread_mutex_unlock(&arg->philo[i].fork.lock);
// 			pthread_mutex_unlock(&arg->philo[i + 1].fork.lock);
// 			pthread_mutex_unlock(&arg->philo[i - 1].fork.lock);
// 			//sleep(5);
// 	}

// 	return (arg);
// }





// t_arg	*taken_fork(t_arg *arg, int i)
// {
// 	if (i % 2 == 0 && i - 1 < (arg->number_of_philosophers + 1))
// 	{
// 		if (arg->philo[i - 1].fork.loking != LOCK)
// 		{
// 			arg->philo[i - 1].fork.loking = LOCK;
// 			view(&arg, (i - 1), arg->philo[i].pid, "has taken a fork");
// 			if(arg->philo[i].fork.loking != LOCK)
// 			{
// 				arg->philo[i].fork.loking = LOCK;
// 				arg->philo[i].eat = LOCK;
// 				view(&arg, (i), arg->philo[i].pid, "has taken a fork");
// 			}
// 		}
// 	}
// 	else
// 	if (i % 2 == 1 && (i - 1) > 0)
// 	{
// 		if (arg->philo[i - 1].fork.loking != LOCK)
// 		{
// 			arg->philo[i - 1].fork.loking = LOCK;
// 			view(&arg, (i - 1), arg->philo[i].pid, "has taken a fork");
// 			if(arg->philo[i].fork.loking != LOCK)
// 			{
// 				arg->philo[i].fork.loking = LOCK;
// 				arg->philo[i].eat = LOCK;
// 				view(&arg, i, arg->philo[i].pid, "has taken a fork");
// 			}
// 		}
// 	}
// 	return (arg);
// }