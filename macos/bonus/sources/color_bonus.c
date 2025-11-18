/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:06:57 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/13 11:37:34 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	ft_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static double	ft_dmod(double x, double y)
{
	long long	div;

	if (y == 0.0)
		return (0.0);
	div = (long long)(x / y);
	return (x - (double)div * y);
}

int	ft_color(double i, int iter, int tint)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i >= (double)iter)
		return (0x000000);
	t = i / (double)iter;
	t = ft_dmod(t * 8.0 + tint * 0.1, 1.0);
	r = (int)(9.0 * (1.0 - t) * t * t * t * 255.0);
	g = (int)(15.0 * (1.0 - t) * (1.0 - t) * t * t * 255.0);
	b = (int)(8.0 * (1.0 - t) * (1.0 - t) * (1.0 - t) * t * 255.0);
	return (ft_trgb(0, r, g, b));
}
