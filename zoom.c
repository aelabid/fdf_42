/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:24:17 by aelabid           #+#    #+#             */
/*   Updated: 2022/01/07 12:24:18 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	ft_zoom(char *path)
{
	int	fd;
	int	nbrow;
	int	zoom;

	fd = open(path, O_RDWR);
	numberofrows(fd, &nbrow);
	if (nbrow > 0 && nbrow <= 50)
		zoom = 20;
	else if (nbrow > 50 && nbrow <= 100)
		zoom = 10;
	else if (nbrow > 100 && nbrow <= 200)
		zoom = 5;
	else
		zoom = 1;
	return (zoom);
}
