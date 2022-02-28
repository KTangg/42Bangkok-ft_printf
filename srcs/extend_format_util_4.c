/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_format_util_4.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:38:04 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/28 22:38:04 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	filling(void *var, size_t n, char c)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)var)[i] = (unsigned char)c;
		i++;
	}
}

static void	*before_signed(size_t min, size_t org, size_t var_size, void *var)
{
	size_t			fill;
	size_t			extend;
	unsigned char	*new;

	extend = var_size - org;
	fill = min - org;
	new = malloc(min);
	if (!new)
		return (0);
	ft_memcpy(new, var, extend);
	filling(&new[extend], fill, '0');
	ft_memcpy(&new[extend + fill], &(((unsigned char *)var)[extend]), org);
	return ((void *)new);
}

static void	*after_signed(size_t min, size_t org, size_t var_size, void *var)
{
	size_t			fill;
	size_t			extend;
	unsigned char	*new;

	extend = var_size - org + 1;
	fill = min - org;
	new = malloc(min);
	if (!new)
		return (0);
	ft_memcpy(new, var, extend);
	filling(&new[extend], fill, '0');
	ft_memcpy(&new[extend + fill], &(((unsigned char *)var)[extend]), org - 1);
	return ((void *)new);
}

int	extend_dot(void **var, size_t *var_size, char **var_format, size_t org)
{
	void			*new;
	size_t			fill;
	size_t			min;
	unsigned char	c;

	*var_format = *var_format + 1;
	min = (size_t)ft_atoi(*var_format);
	c = (unsigned char *)var[*var_size - org];
	if (min > org)
	{
		fill = min - org;
		if (c == '-')
			new = after_signed(min, org, *var_size, *var);
		else
			new = before_signed(min, org, *var_size, *var);
		free(*var);
		*var_size = *var_size + fill;
		if (!new)
			return (0);
		*var = new;
	}
	return (1);
}
