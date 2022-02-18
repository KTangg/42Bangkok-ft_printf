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

static char	*add_minus(char *nbr)
{
	char	*tmp;
	char	*minus;

	tmp = nbr;
	minus = "-";
	nbr = ft_strjoin(minus, nbr);
	free(tmp);
	return (nbr);
}

static char	*int_to_hex(long nbr, int mode)
{
	int		minus;
	char	*base_16;
	char	*hex_str;

	minus = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		minus = 1;
	}
	base_16 = "0123456789ABCDEF";
	if (mode == 0)
		base_16 = "0123456789abcdef";
	hex_str = create_hex_char(nbr, base_16);
	if (!hex_str)
		return (NULL);
	if (minus)
		hex_str = add_minus(hex_str);
	return (hex_str);
}

char	*get_hexl(va_list *arg)
{
	int		nbr;
	char	*str;

	nbr = va_arg(*arg, int);
	str = int_to_hex(nbr, 0);
	return (str);
}

char	*get_hexu(va_list *arg)
{
	int		nbr;
	char	*str;

	nbr = va_arg(*arg, int);
	str = int_to_hex(nbr, 1);
	return (str);
}
