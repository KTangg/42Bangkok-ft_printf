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

char	*extend_format_n_2(char *var_format, void *var, size_t *var_size)
{
	size_t	org_size;

	org_size = *var_size;
	if (*var_format == '-')
		if (!extend_right(&var, var_size, &var_format))
			return (NULL);
	if (*var_format == '.')
	{
		if (!extend_dot(&var, var_size, &var_format, org_size))
			return (NULL);
	}
	else
	{
		var_format = var_format - 1;
		if (!extend_min(&var, var_size, &var_format, org_size))
			return (NULL);
	}
	return (var);
}

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
		return (extend_format_n_2(var_format, var, var_size));
	return (var);
}

int	cutting_flag(void **var, size_t *var_size, char **var_format)
{
	size_t			max;
	unsigned char	*new;

	*var_format = *var_format + 1;
	max = (size_t)ft_atoi(*var_format);
	if (max < *var_size)
	{
		new = malloc(max);
		if (!new)
		{
			free(var);
			return (0);
		}
		if (max != 0)
			ft_memcpy(new, *var, max);
		free(*var);
		*var_size = max;
		*var = (void *)new;
	}
	return (1);
}

char	*extend_format_s(char *var_format, void *var, size_t *var_size)
{
	size_t	org_size;

	org_size = *var_size;
	if (*var_format == '0')
		if (!extend_zero(&var, var_size, &var_format, org_size))
			return (NULL);
	if (*var_format == ' ')
		if (!extend_min(&var, var_size, &var_format, org_size))
			return (NULL);
	if (*var_format == '-')
		if (!extend_right(&var, var_size, &var_format))
			return (NULL);
	if (*var_format == '.')
	{
		if (!cutting_flag(&var, var_size, &var_format))
			return (NULL);
	}
	else
	{
		var_format = var_format - 1;
		if (!extend_min(&var, var_size, &var_format, org_size))
			return (NULL);
	}
	return (var);
}
