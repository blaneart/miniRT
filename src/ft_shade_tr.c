/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shade_tr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:50:37 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/12 22:05:38 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ray.h"

int		ft_shade_tr(t_info info, t_vector d, t_tr *tr, t_vector norm)
{
	t_vector	l[2];
	t_vector	coef[2];
	t_l			*light;

	ft_fill_v(&coef[0], 0, 0, 0);
	ft_fill_v(&coef[1], 0, 0, 0);
	light = info.l;
	l[1] = d;
	while (light)
	{
		l[0] = ft_vsbst(light->coor, ft_vecsum(d, info.cam->o));
		norm = ft_norm_pl(norm, info.cam->norm);
		if (ft_check_obst(info, l[0], d) == 0 && ft_dot_product(l[0], norm) > 0)
		{
			coef[0] = ft_get_coef(coef[0], l[0], norm, light);
			ft_get_spec(&coef[1], l, light, norm);
		}
		light = light->next;
	}
	return (ft_color(coef, tr->color, info));
}
