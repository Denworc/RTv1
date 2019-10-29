/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaksymy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 04:26:50 by smaksymy          #+#    #+#             */
/*   Updated: 2017/10/31 05:28:42 by smaksymy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rtv1.h"

void	init_info(t_mlx *i)
{
	ft_strequ(i->av, "1") ? (i->title = "Scene_1") : (0);
	ft_strequ(i->av, "2") ? (i->title = "Scene_2") : (0);
	ft_strequ(i->av, "3") ? (i->title = "Scene_3") : (0);
	ft_strequ(i->av, "4") ? (i->title = "Scene_4") : (0);
	ft_strequ(i->av, "5") ? (i->title = "Scene_5") : (0);
	i->rotx = 0.0;
	i->roty = 0.0;
	i->rotz = 0.0;
	i->img = NULL;
	i->fn = 1;
}

int		key_hook(int keycode, t_mlx *info)
{
	if (keycode == 53)
	{
		mlx_clear_window(info->mlx, info->win);
		mlx_destroy_window(info->mlx, info->win);
		exit(0);
	}
	return (0);
}

void	my_hooks(t_mlx *i)
{
	mlx_hook(i->win, 2, 0, key_hook, i);
	mlx_hook(i->win, 17, 0, exit_hook, i);
	mlx_loop(i->mlx);
}

void	my_run(t_mlx *i, char *av)
{
	if (!(ft_strequ(av, "1") || ft_strequ(av, "2") ||
			ft_strequ(av, "3") || ft_strequ(av, "4") ||
			ft_strequ(av, "5")))
		ft_error_check(1);
	i->av = av;
	i->mlx = mlx_init();
	init_info(i);
	i->win = mlx_new_window(i->mlx, 1000, 700, i->title);
	make_im(i);
	my_hooks(i);
}

int		main(int ac, char **av)
{
	t_mlx	i;
	int		j;

	if (ac == 2)
		my_run(&i, av[1]);
	else
		ft_error_check(1);
	return (0);
}
