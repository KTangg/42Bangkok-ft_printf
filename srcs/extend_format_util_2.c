/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_format_util_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 20:54:18 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/28 20:54:18 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*extend_format_n(char *var_format, void *var, size_t *var_size)
{
	char	c;
	size_t	org_size;

	c = var_format[ft_strlen(var_format) - 1];
	org_size = *var_size;
	if (*var_format == '#')
		if (!extend_hex(&var, var_size, &var_format, c))
			return (NULL);
	if (*var_format == '+')
		if (!extend_pos(&var, var_size, &var_format))
			return (NULL);
	if (*var_format == ' ')
		if (!extend_spc(&var, var_size, &var_format))
			return (NULL);
	if (*var_format == '0')
	{
		if (!extend_zero(&var, var_size, &var_format, org_size))
			return (NULL);
	}
	else
	{
		if (!extend_min(&var, var_size, &var_format, org_size))
			return (NULL);
	}
	return (var);
}

char	*extend_format_s(char *var_format, void *var, size_t *var_size)
{
	char	c;
	size_t	org_size;

	c = var_format[ft_strlen(var_format) - 1];
	org_size = *var_size;
	if (*var_format == '#')
		if (!extend_hex(&var, var_size, &var_format, c))
			return (NULL);
	if (*var_format == '+')
		if (!extend_pos(&var, var_size, &var_format))
			return (NULL);
	if (*var_format == '0')
		if (!extend_zero(&var, var_size, &var_format, org_size))
			return (NULL);
	if (*var_format == ' ')
	{
		if (!extend_min(&var, var_size, &var_format, org_size))
			return (NULL);
	}
	else
	{
		if (!extend_min(&var, var_size, &var_format, org_size))
			return (NULL);
	}
	return (var);
}
