/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atod.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skarayil <skarayil@student.42kocaeli>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 17:02:57 by skarayil          #+#    #+#             */
/*   Updated: 2025/11/06 19:54:00 by skarayil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	ft_handle_sign(const char **str, double *sign)
{
	*sign = 1.0;
	if (**str == '+' || **str == '-')
	{
		if (**str == '-')
			*sign = -1.0;
		(*str)++;
	}
	if (**str == '\0')
		return (false);
	return (true);
}

static bool	ft_handle_integer(const char **str, double *integer)
{
	*integer = 0.0;
	if (!(**str >= '0' && **str <= '9'))
		return (false);
	while (**str >= '0' && **str <= '9')
	{
		*integer = *integer * 10.0 + (double)(**str - '0');
		(*str)++;
	}
	return (true);
}

static bool	ft_handle_decimal(const char **str, double *decimal)
{
	double	factor;

	*decimal = 0.0;
	if (**str != '.')
		return (true);
	(*str)++;
	factor = 1.0;
	if (!(**str >= '0' && **str <= '9'))
		return (false);
	while (**str >= '0' && **str <= '9')
	{
		factor *= 10.0;
		*decimal = *decimal * 10.0 + (double)(**str - '0');
		(*str)++;
	}
	*decimal = *decimal / factor;
	return (true);
}

bool	ft_atod(const char *str, double *result)
{
	double	sign;
	double	integer;
	double	decimal;

	if (!str || !result || *str == '\0')
		return (false);
	if (!ft_handle_sign(&str, &sign))
		return (false);
	if (!ft_handle_integer(&str, &integer))
		return (false);
	if (!ft_handle_decimal(&str, &decimal))
		return (false);
	if (*str != '\0')
		return (false);
	*result = (integer + decimal) * sign;
	return (true);
}
