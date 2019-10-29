/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:41:03 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 04:41:57 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	fill_scene1(t_mlx *i)
{
	i->cone.s_point = vector(0, 0, 0);
	i->cone.rot = vector(1, 1, 1);
	i->cone.a = 10 * (3.141592654 / 180);
	i->elem[0].color = color(255, 255, 255, 0);
	i->elem[0].elem = &i->cone;
	i->elem[0].i = 4;
	i->l.s_point = vector(1900, 1200, -1600);
}

void	scene_1(t_mlx *i, int mx, int p[2], int x[3])
{
	t_r		r_cur;

	r_cur.s_point = vector(100, 100, -3100);
	fill_scene1(i);
	x[0] = p[0] - 1;
	while (++x[0] < p[1])
	{
		while (++x[1] < mx)
			tracing(i, x[1], x[0], r_cur);
		x[1] = -1;
	}
}
