/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:38:03 by aelabid           #+#    #+#             */
/*   Updated: 2022/01/18 17:12:28 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	signex(int x1, int x2)
{
	if (x1 < x2)
		return (1);
	else
		return (-1);
}

int	signey(int y1, int y2)
{
	if (y1 < y2)
		return (1);
	else
		return (-1);
}

void	freep(t_point *f, t_point *s)
{
	free(f);
	free(s);
}

void	line(t_point *f, t_point *s, t_data img, int color)
{
	t_point	delta;
	t_point	*cur;
	int		error[2];

	delta.x = abs(s->x - f->x);
	delta.y = abs(s->y - f->y);
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur->x != s->x || cur->y != s->y)
	{
		my_mlx_pixel_put(&img, cur->x, cur->y, color);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur->x += signex(f->x, s->x);
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur->y += signey(f->y, s->y);
		}
	}
	freep(f, s);
}
