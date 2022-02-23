/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_format_util_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:29:45 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/23 17:29:45 by spoolpra         ###   ########.fr       */
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
	new = malloc(min);
	if (!new)
		return (0);
	ft_memcpy(new, var, extend);
	filling(&new[extend], fill, '0');
	ft_memcpy(&new[extend + fill], &(((unsigned char *)var)[extend]), org - 1);
	return ((void *)new);
}

int	extend_zero(void **var, size_t *var_size, char **var_format, size_t org)
{
	void			*new_var;
	size_t			min;
	unsigned char	c;

	*var_format = *var_format + 1;
	min = (size_t)ft_atoi(*var_format);
	c = ((unsigned char *)*var)[0];
	if (min > *var_size)
	{
		if (c == '-')
			new_var = after_signed(min, org, *var_size, *var);
		else
			new_var = before_signed(min, org, *var_size, *var);
		free(*var);
		*var_size = min;
		if (!new_var)
			return (0);
		*var = new_var;
	}
	return (1);
}

int	extend_min(void **var, size_t *var_size, char **var_format, size_t org)
{
	size_t			fill;
	size_t			extend;
	size_t			min;
	unsigned char	*new_var;

	*var_format = *var_format + 1;
	min = (size_t)ft_atoi(*var_format);
	extend = *var_size - org;
	if (min > *var_size)
	{
		fill = min - *var_size;
		new_var = malloc(min);
		if (!new_var)
		{
			free(var);
			return (0);
		}
		ft_memcpy(new_var, *var, *var_size - org);
		filling(&new_var[extend], fill, ' ');
		ft_memcpy(&new_var[extend + fill], &(((unsigned char *)*var)[extend]), org);
		free(*var);
		*var_size = min;
		*var = (void *)new_var;
	}
	return (1);
}