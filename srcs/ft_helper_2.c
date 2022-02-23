/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:20:24 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/19 23:20:24 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	int_size(long n)
{
	size_t	size;

	size = 0;
	if (n < 0)
		size = 1;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		size = size + 1;
	}
	return (size);
}

static char	*to_alpha(long n, int size, char *str)
{
	if (n > 9)
		str = to_alpha(n / 10, size - 1, str);
	str[size - 1] = (n % 10) + '0';
	return (str);
}

char	*ft_itoa(long n)
{
	int			size;
	char		*str;

	size = int_size(n);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	str = to_alpha(n, size, str);
	str[size] = '\0';
	return (str);
}

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	result;
	long int	negative;

	result = 0;
	negative = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			negative = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = result * 10;
		result = result + (*nptr - '0');
		nptr++;
	}
	result = result * negative;
	return (result);
}
