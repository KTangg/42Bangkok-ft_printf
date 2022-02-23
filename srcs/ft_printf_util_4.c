/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:49:54 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/23 12:49:54 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*create_hex_char(unsigned long nbr, char *base_16)
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

static char	*int_to_hex(unsigned long nbr, int mode)
{
	char	*base_16;
	char	*hex_str;

	base_16 = "0123456789ABCDEF";
	if (mode == 0)
		base_16 = "0123456789abcdef";
	hex_str = create_hex_char(nbr, base_16);
	return (hex_str);
}

void	*get_ptr(va_list *arg, size_t *var_size)
{
	char			*hex;
	void			*var;
	unsigned char	*ptr;

	ptr = (unsigned char *)va_arg(*arg, void *);
	hex = int_to_hex((unsigned long)ptr, 0);
	if (!hex)
		return (NULL);
	*var_size = ft_strlen(hex) + 2;
	var = (void *)ft_strjoin("0x", hex);
	free(hex);
	return (var);
}
