/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablanar <ablanar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 16:33:52 by ablanar           #+#    #+#             */
/*   Updated: 2020/02/11 15:23:19 by ablanar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ray.h"

int		ft_reader_tab_help(char **line)
{
	if (line[0][1] == 'y')
		return (ft_check_cy(line));
	if (line[0][1] == '\0')
		return (ft_check_c(line));
	return (-1);
}

int		ft_reader_tab(char **line)
{
	if (line[0][0] == 'R')
		return (ft_check_res(line));
	if (line[0][0] == 'A')
		return (ft_check_a(line));
	if (line[0][0] == 'c')
		return (ft_reader_tab_help(line));
	if (line[0][0] == 'l')
		return (ft_check_l(line));
	if (line[0][0] == 'p')
		return (ft_check_plane(line));
	if (line[0][0] == 't')
		return (ft_check_tr(line));
	if (line[0][0] == 's')
	{
		if (line[0][1] == 'p')
			return (ft_check_l(line));
		if (line[0][1] == 'q')
			return (ft_check_sq(line));
	}
	return (-1);
}

int		ft_check_input(char *line)
{
	char	**tab;
	int		k;

	k = 0;
	if (line == NULL || line[0] == '\0')
		return (0);
	if (!(tab = ft_split(line, ' ')))
		return (-1);
	if (ft_reader_tab(tab) == -1)
	{
		ft_free_tab(tab);
		return (-1);
	}
	return (ft_free_tab(tab));
}
