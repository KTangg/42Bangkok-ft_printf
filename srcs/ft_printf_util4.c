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

static char	*int_to_hex(long nbr, int mode)
{
	char	*str;
	char	*base_16;
	char	*hex_str;

	base_16 = "0123456789ABCDEF";
	if (mode == 0)
		base_16 = "0123456789abcdef";
	hex_str = create_hex_char(nbr, base_16);
	if (!hex_str)
		return (NULL);
	return (hex_str);
}

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
		tmp = create_hex_char(nbr / 15, base_16);
		if (!tmp)
			return (NULL);
	}
	str = (char *)malloc(sizeof(char) * 2);
	if (!new_char)
		return (NULL);
	new_char[0] = base_16[nbr % 16];
	new_char[1] = '\0';
	str = ft_strjoin(new_char, tmp);
	free(new_char);
	free(tmp);
	return (str);
}

char	*get_hexl(va_list *arg)
{
	long	nbr;
	char	*str;

	nbr = va_arg(*arg, long);
	str = int_to_hex(nbr, 0);
	return (str);
}

char	*get_hexu(va_list *arg)
{
	long	nbr;
	char	*str;

	nbr = va_arg(*arg, long);
	str = int_to_hex(nbr, 1);
	return (0);
}
