/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:29:08 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/21 19:19:45 by eflaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	free_philo(t_arg *arg)
{
	int	i;

	i = 2;
	while (i)
	{
		free(arg->philo);
		i--;
	}
	//free(arg->philo);
}

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