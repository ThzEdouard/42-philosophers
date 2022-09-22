/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflaquet <eflaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:29:08 by eflaquet          #+#    #+#             */
/*   Updated: 2022/09/22 18:47:44 by eflaquet         ###   ########.fr       */
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}