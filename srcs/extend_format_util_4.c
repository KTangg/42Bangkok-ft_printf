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

size_t	find_start(void *var, size_t *var_size, size_t *org)
{
	int				i;
	size_t			org_size;
	unsigned char	*str;

	i = *var_size - 1;
	org_size = 0;
	str = (unsigned char *)var;
	while (i >= 0)
	{
		if (str[i] == '-' || str[i] == 'x' || str[i] == 'X')
		{
			*org = org_size;
			return (i + 1);
		}
		org_size++;
		i--;
	}
	*org = org_size;
	return (0);
}

int	extend_dot_0(void **var, size_t *var_size)
{
	unsigned char	*new;

	new = (unsigned char *)malloc(0);
	if (!new)
		return (0);
	free(*var);
	*var_size = 0;
	*var = new;
	return (1);
}

int	extend_dot(void **var, size_t *var_size, char **var_format, size_t org)
{
	size_t			min;
	size_t			fill;
	size_t			start;
	unsigned char	*new;

	*var_format = *var_format + 1;
	min = (size_t)ft_atoi(*var_format);
	start = find_start(*var, var_size, &org);
	if (min == 0 && *var_size == 1 && ((char *)*var)[0] == '0')
		return (extend_dot_0(var, var_size));
	if (min > org)
	{
		fill = min - org;
		new = (unsigned char *)malloc(fill + *var_size);
		if (!new)
			return (0);
		ft_memcpy(new, *var, start);
		filling(&new[start], fill, '0');
		ft_memcpy(&new[start + fill], (*var + start), org);
		free(*var);
		*var_size = *var_size + fill;
		*var = new;
	}
	return (1);
}
