/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:46:13 by ablanar           #+#    #+#             */
/*   Updated: 2019/12/30 17:49:30 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

int	ft_atoi(char *s)
{
	int num;
	int sign;

	sign = 1;
	num = 0;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9' && *s != '\0')
	{
		num = num * 10 + (*s - 48);
		s++;
	}
	return (num * sign);
}
