/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_util_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:19:35 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/23 14:19:35 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	dup_flag(char *format)
{
	int	i;
	int	j;

	i = 0;
	while (format[i] != '\0')
	{
		j = 0;
		while (j < i)
		{
			if (format[i] == ' ' && format[j] == '+')
				return (1);
			if (format[i] == '+' && format[j] == ' ')
				return (1);
			if (format[j] == format[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	valid_prefix_conv(char c, char format)
{
	if (format == '#')
		if (c != 'x' && c != 'X')
			return (0);
	if (format == ' ' || format == '+')
		if (c != 'd' && c != 'i')
			return (0);
	return (1);
}

static int	valid_zero_conv(char c)
{
	if (c != 'i' && c != 'u' && c != 'd' && c != 'x' && c != 'X')
		return (0);
	return (1);
}

static int	valid_prefix(char *format)
{
	char	conv;

	conv = format[ft_strlen(format) - 1];
	if (*format == '#' || *format == ' ' || *format == '+')
	{
		if (!valid_prefix_conv(conv, *format))
			return (0);
		format++;
	}
	if (*format == '0')
	{
		if (!valid_zero_conv(conv))
			return (0);
		format++;
	}
	while (ft_isdigit(*format))
		format++;
	if (*format != conv)
		return (0);
	return (1);
}

int	valid_flag(char *format)
{
	if (dup_flag(format))
	{
		free(format);
		return (0);
	}
	if (!valid_prefix(format))
	{
		free(format);
		return (0);
	}
	return (1);
}
