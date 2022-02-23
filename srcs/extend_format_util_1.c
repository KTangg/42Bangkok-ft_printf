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

int	extend_zero(void **var, size_t *var_size, char **var_format, size_t org)
{
	int		min;
	void	*new_var;
	size_t	fill;
	size_t	extend;

	*var_format = *var_format + 1;
	min = ft_atoi(*var_format);
	extend = *var_size - org;
	if (min < 0)
		return (0);
	if (min > *var_size)
	{
		fill = min - *var_size;
		new_var = malloc(min);
		if (!new_var)
			return (0);
		ft_memcpy(new_var, *var, *var_size - org);
		filling(&new_var[extend], fill, '0');
		ft_memcpy(&new_var[extend + fill], &((*var)[extend]), org);
		free(*var);
		*var_size = min;
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
	if (min < 0)
		return (0);
	if (min > *var_size)
	{
		fill = min - *var_size;
		new_var = malloc(min);
		if (!new_var)
			return (0);
		ft_memcpy(new_var, *var, *var_size - org);
		filling(&new_var[extend], fill, ' ');
		ft_memcpy(&new_var[extend + fill], &((*var)[extend]), org);
		free(*var);
		*var_size = min;
		*var = (void *)new_var;
	}
	return (1);
}
