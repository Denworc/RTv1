/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:38:43 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:31:01 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	fill_scene3(t_mlx *i)
{
	i->s.c = vector(50, 100, 200);
	i->s.r = 200;
	i->elem[0].color = color(0, 0, 255, 0);
	i->elem[0].elem = &i->s;
	i->elem[0].i = 1;
	i->l.s_point = vector(-600, 600, -600);
}

void	scene_3(t_mlx *i, int mx, int p[2], int x[3])
{
	t_r		r_cur;

	r_cur.s_point = vector(0, 0, -1100);
	fill_scene3(i);
	x[0] = p[0] - 1;
	while (++x[0] < p[1])
	{
		while (++x[1] < mx)
			tracing(i, x[1], x[0], r_cur);
		x[1] = -1;
	}
}
