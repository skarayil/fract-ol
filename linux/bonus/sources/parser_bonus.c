/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 12:29:47 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/13 18:44:05 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include <unistd.h>

static void	ft_warning(void)
{
	write(1, "\n=== Fractol Usage ===\n\n", 25);
	write(1, "Celtic\n", 8);
	write(1, "  ./fractol_bonus celtic\n\n", 27);
	write(1, "Tricorn\n", 9);
	write(1, "  ./fractol_bonus tricorn\n\n", 28);
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

static bool	ft_type(const char *name, t_env *f)
{
	if (ft_streq(name, "celtic"))
		return (f->ftype = CELTIC, true);
	if (ft_streq(name, "tricorn"))
		return (f->ftype = TRICORN, true);
	return (false);
}

bool	ft_parser(int ac, char *av[], t_env *f)
{
	if (!av || ac < 2)
		return (ft_warning(), false);
	if (!ft_type(av[1], f))
		return (ft_warning(), false);
	if ((f->ftype == CELTIC || f->ftype == TRICORN) && ac > 2)
		return (ft_warning(), false);
	return (true);
}
