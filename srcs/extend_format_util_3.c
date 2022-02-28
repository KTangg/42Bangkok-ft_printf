/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_format_util_3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 21:46:09 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/28 21:46:09 by spoolpra         ###   ########.fr       */
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

int	extend_right(void **var, size_t *var_size, char **var_format)
{
	size_t			fill;
	size_t			min;
	unsigned char	*new;

	*var_format = *var_format + 1;
	min = (size_t)ft_atoi(*var_format);
	if (min > *var_size)
	{
		fill = min - *var_size;
		new = malloc(min);
		if (!new)
		{
			free(var);
			return (0);
		}
		ft_memcpy(new, *var, *var_size);
		filling(&new[*var_size], fill, ' ');
		free(*var);
		*var_size = min;
		*var = (void *)new;
	}
	return (1);
}

int	extend_min(void **var, size_t *var_size, char **var_format, size_t org)
{
	size_t			fill;
	size_t			ext;
	size_t			min;
	unsigned char	*new;

	*var_format = *var_format + 1;
	min = (size_t)ft_atoi(*var_format);
	ext = *var_size - org;
	if (min > *var_size)
	{
		fill = min - *var_size;
		new = malloc(min);
		if (!new)
		{
			free(var);
			return (0);
		}
		ft_memcpy(new, *var, *var_size - org);
		filling(&new[ext], fill, ' ');
		ft_memcpy(&new[ext + fill], &(((unsigned char *)*var)[ext]), org);
		free(*var);
		*var_size = min;
		*var = (void *)new;
	}
	return (1);
}
