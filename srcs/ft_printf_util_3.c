/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 15:14:33 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/18 15:14:33 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*create_hex_char(long nbr, char *base_16)
{
	char	*tmp;
	char	*str;
	char	*new_char;

	tmp = (char *)malloc(sizeof(char) * 1);
	if (!tmp)
		return (NULL);
	tmp[0] = '\0';
	if (nbr > 15)
	{
		free(tmp);
		tmp = create_hex_char(nbr / 16, base_16);
		if (!tmp)
			return (NULL);
	}
	new_char = (char *)malloc(sizeof(char) * 2);
	if (!new_char)
		return (NULL);
	new_char[0] = base_16[nbr % 16];
	new_char[1] = '\0';
	str = ft_strjoin(tmp, new_char);
	free(new_char);
	free(tmp);
	return (str);
}

static char	*int_to_hex(long nbr, int mode)
{
	int		minus;
	char	*base_16;
	char	*hex_str;

	if (nbr < 0)
		nbr = 4294967295 + (nbr + 1);
	base_16 = "0123456789ABCDEF";
	if (mode == 0)
		base_16 = "0123456789abcdef";
	hex_str = create_hex_char(nbr, base_16);
	return (hex_str);
}

void	*get_hex(va_list *arg, size_t *var_size, int mode)
{
	int		nbr;
	char	*str;
	void	*var;
	size_t	len;

	nbr = va_arg(*arg, int);
	str = int_to_hex(nbr, mode);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (len > 8)
	{
		*var_size = 8;
		var = malloc(*var_size);
		if (var)
			var = ft_memcpy(var, &str[len - 7], 8);
		return (var);
	}
	*var_size = len;
	var = malloc(*var_size);
	if (var)
		var = ft_memcpy(var, str, len);
	return (var);
}

void	*get_ptr(va_list *arg, size_t *var_size)
{
	(void)arg;
	(void)var_size;
	return (NULL);
}
