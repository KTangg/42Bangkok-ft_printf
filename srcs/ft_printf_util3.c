/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 03:31:52 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/18 03:31:52 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_ud(va_list *arg)
{
	char			*str;
	int				i;
	unsigned int	u;

	i = va_arg(*arg, int);
	u = (unsigned int)i;
	str = ft_itoa(u);
	return (str);
}

char	*get_percent(void)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (0);
}
