/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:06:48 by aelabid           #+#    #+#             */
/*   Updated: 2022/01/18 16:07:34 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	main(int av, char **ac)
{
	t_mlx	mlx;
	t_data	img;
	int		fd;
	int		zoom;

	if (av == 2)
	{
		fd = open(ac[1], O_RDWR);
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1800, 1200, "Hello world!");
		mlx.img = mlx_new_image(mlx.mlx_ptr, 1800, 1200);
		img.addr = mlx_get_data_addr(mlx.img, &img.bits_per_pixel,
				&img.line_len, &img.endian);
		zoom = ft_zoom(ac[1]);
		drawmap(zoom, img, fd, ac[1]);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
		mlx_key_hook(mlx.win_ptr, &handle_input, &mlx);
		mlx_loop(mlx.mlx_ptr);
	}
	else
		write(2, "no map is here", 14);
	return (0);
}
