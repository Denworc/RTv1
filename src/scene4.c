/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:42:05 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:28:56 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	fill_scene4(t_mlx *i)
{
	i->c.s_point = vector(200, 400, -900);
	i->c.rot = vector(1, 0, 0);
	i->c.r = 200;
	i->elem[0].color = color(255, 0, 0, 0);
	i->elem[0].elem = &i->c;
	i->elem[0].i = 2;
	i->l.s_point = vector(0, 0, -1600);
}

void	scene_4(t_mlx *i, int mx, int p[2], int x[3])
{
	t_r		r_cur;

	r_cur.s_point = vector(800, 500, -2100);
	fill_scene4(i);
	x[0] = p[0] - 1;
	while (++x[0] < p[1])
	{
		while (++x[1] < mx)
			tracing(i, x[1], x[0], r_cur);
		x[1] = -1;
	}
}
