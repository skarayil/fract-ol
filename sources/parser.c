/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:29:40 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/13 18:45:51 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

static void	ft_warning(void)
{
	write(1, "\n=== Fractol Usage ===\n\n", 25);
	write(1, "Mandelbrot\n", 12);
	write(1, "  ./fractol mandelbrot\n\n", 25);
	write(1, "Julia\n", 6);
	write(1, "  ./fractol julia [real] [imaginary]\n", 38);
	write(1, "  Example: ./fractol julia 0.3 0.5\n", 36);
	write(1, "  Example: ./fractol julia -0.4 0.6\n", 37);
	write(1, "  Example: ./fractol julia -0.75 0.11\n", 39);
	write(1, "  Example: ./fractol julia -0.8 0.156\n\n", 40);
	write(1, "Controls\n", 10);
	write(1, "  Mouse wheel    : Zoom in/out at cursor\n", 42);
	write(1, "  Arrow keys     : Move view\n", 30);
	write(1, "  +/-            : Change iteration depth\n", 43);
	write(1, "  C              : Cycle color schemes\n", 40);
	write(1, "  ESC            : Exit program\n\n", 34);
}

static bool	ft_streq(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 == '\0' && *s2 == '\0');
}

static bool	ft_parse_julia(int ac, char *av[], t_env *f)
{
	double	cr;
	double	ci;

	if (ac == 4)
	{
		if (!ft_atod(av[2], &cr) || !ft_atod(av[3], &ci))
		{
			write(2, "Error: Invalid number format\n", 30);
			return (false);
		}
		if ((cr < -4.0 || cr > 4.0 || ci < -4.0 || ci > 4.0))
		{
			write(2, "Error: Julia parameters must be between -4.0, 4.0\n", 51);
			return (false);
		}
		f->fdata.julia.real = cr;
		f->fdata.julia.imag = ci;
	}
	return (true);
}

static bool	ft_type(const char *name, t_env *f)
{
	if (ft_streq(name, "mandelbrot"))
		return (f->ftype = MANDELBROT, true);
	if (ft_streq(name, "julia"))
		return (f->ftype = JULIA, true);
	return (false);
}

bool	ft_parser(int ac, char *av[], t_env *f)
{
	if (!av || ac < 2)
		return (ft_warning(), false);
	if (!ft_type(av[1], f))
		return (ft_warning(), false);
	if (f->ftype == MANDELBROT && ac > 2)
		return (ft_warning(), false);
	if (f->ftype == JULIA && ac != 4)
		return (ft_warning(), false);
	if (f->ftype == JULIA && !ft_parse_julia(ac, av, f))
		return (false);
	return (true);
}
