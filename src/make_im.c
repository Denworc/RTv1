/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_im.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:36:24 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:27:41 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	*operate_fl(void *th)
{
	t_f		*fl;
	int		p[2];
	int		x[3];

	x[0] = -1;
	x[1] = -1;
	x[2] = -1;
	fl = (t_f*)th;
	p[0] = fl->y;
	p[1] = (700 / fl->i->fn + fl->y);
	ft_strequ(fl->i->av, "1") ? scene_1(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "2") ? scene_2(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "3") ? scene_3(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "4") ? scene_4(fl->i, 1000, p, x) : (0);
	ft_strequ(fl->i->av, "5") ? scene_5(fl->i, 1000, p, x) : (0);
	pthread_exit(NULL);
}

void	add_f(t_mlx *i)
{
	int			j;
	pthread_t	th[i->fn];
	t_f			fl[i->fn];

	j = -1;
	while (++j < i->fn)
	{
		fl[j].y = j * 700 / i->fn;
		fl[j].i = i;
		pthread_create(&th[j], NULL, operate_fl, (void*)&fl[j]);
	}
	j = -1;
	while (++j < i->fn)
		pthread_join(th[j], NULL);
}

void	make_im(t_mlx *i)
{
	if (i->img != NULL)
		mlx_destroy_image(i->mlx, i->img);
	i->img = mlx_new_image(i->mlx, 1000, 700);
	i->tab = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->e);
	add_f(i);
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
}
