/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 05:02:47 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:27:24 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

int		ft_error_check(int n)
{
	if (n == 1)
	{
		ft_putstr("usage: ./Rtv1 (1-5)\n1 - Scene_1\n2 - Scene_2\n");
		ft_putstr("3 - Scene_3\n4 - Scene_4\n5 - Scene_5\n");
		exit(0);
	}
	return (0);
}

int		exit_hook(t_mlx *info)
{
	mlx_clear_window(info->mlx, info->win);
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
	return (0);
}
