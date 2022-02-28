/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extend_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:26:55 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/23 16:26:55 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	extend_min(void **var, size_t *var_size, char **var_format, size_t org);
int	extend_zero(void **var, size_t *var_size, char **var_format, size_t org);

static int	extend_hex(void **var, size_t *var_size, char **var_format, char c)
{
	void	*new_var;
	void	*prefix;
	char	*prefix_str;

	*var_format = *var_format + 1;
	if (((unsigned char *)*var)[0] == '0')
		return (1);
	prefix_str = "0x";
	if (c == 'X')
		prefix_str = "0X";
	prefix = malloc(2);
	if (!prefix)
	{
		free(*var);
		return (0);
	}
	prefix = ft_memcpy(prefix, prefix_str, 2);
	new_var = memjoin(prefix, *var, 2, *var_size);
	if (!new_var)
		return (0);
	*var_size = *var_size + 2;
	*var = new_var;
	return (1);
}

static int	extend_pos(void **var, size_t *var_size, char **var_format)
{
	void	*new_var;
	void	*prefix;
	char	*prefix_str;

	prefix_str = "+";
	*var_format = *var_format + 1;
	prefix = malloc(1);
	if (!prefix)
		return (0);
	prefix = ft_memcpy(prefix, prefix_str, 1);
	if (((unsigned char *)*var)[0] != '-')
	{
		new_var = memjoin(prefix, *var, 1, *var_size);
		if (!new_var)
			return (0);
		*var_size = *var_size + 1;
		*var = new_var;
		return (1);
	}
	free(prefix);
	return (1);
}

static int	extend_spc(void **var, size_t *var_size, char **var_format)
{
	void	*new_var;
	void	*prefix;
	char	*prefix_str;

	*var_format = *var_format + 1;
	prefix_str = " ";
	prefix = malloc(1);
	if (!prefix)
		return (0);
	prefix = ft_memcpy(prefix, prefix_str, 1);
	if (((unsigned char *)*var)[0] != '-')
	{
		new_var = memjoin(prefix, *var, 1, *var_size);
		if (!new_var)
			return (0);
		*var_size = *var_size + 1;
		*var = new_var;
		return (1);
	}
	free(prefix);
	return (1);
}

char	*extend_format(char *var_format, void *var, size_t *var_size)
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
	{
		if (!extend_zero(&var, var_size, &var_format, org_size))
			return (NULL);
	}
	else
	{
		if (!extend_min(&var, var_size, &var_format, org_size))
			return (NULL);
	}
	if (*var_format == ' ')
		if (!extend_spc(&var, var_size, &var_format))
			return (NULL);
	return (var);
}
