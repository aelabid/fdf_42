/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 08:19:51 by aelabid           #+#    #+#             */
/*   Updated: 2022/01/07 08:19:52 by aelabid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

static int	val(char c)
{
	if (c >= '0' && c <= '9')
		return ((int)c - '0');
	else
		return ((int)c - 'A' + 10);
}

int	ft_convert(char *str)
{
	int	power;
	int	num;
	int	i;

	power = 1;
	num = 0;
	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		num += val(str[i]) * power;
		power = power * 16;
		i--;
	}
	return (num);
}
