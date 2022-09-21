/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:12:35 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/22 00:21:41 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

// static int	ft_isdigit(int c)
// {
// 	if (c >= 48 && c <= 57)
// 		return (1);
// 	return (0);
// }

// static int	verif_arg(char **argv, int i)
// {
// 	unsigned int	x;

// 	x = 0;
// 	while (argv[i])
// 	{
// 		while (argv[i][x])
// 		{
// 			if (ft_isdigit(argv[i][x]))
// 				return (0);
// 			x++;
// 		}
// 		i++;
// 	}
// 	return (1);
// }

int	main(int argc, char **argv)
{
	t_arg	arg;

	if ((argc == 5  ||  argc == 6))
	{
		arg.number_of_philosophers = u_atoi(argv[1]);
		arg.time_to_die = u_atoi(argv[2]);
		arg.time_to_eat = u_atoi(argv[3]);
		arg.time_to_sleep = u_atoi(argv[4]);
		if (argc == 6)
			arg.number_of_times_each_philosopher_must_eat = u_atoi(argv[5]);
		creating_philo(&arg);
		sleep(3);
		//delete_philo(&arg);
	}
	else
		printf("use ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep "
			"[number_of_times_each_philosopher_must_eat]");
	return (0);
}