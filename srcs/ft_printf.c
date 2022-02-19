/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:50:48 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/18 18:29:53 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	char	*str;
	va_list	arg;
	va_list	*ptr;

	va_start(arg, format);
	ptr = &arg;
	i = 0;
	str = create_str((char *)format, ptr, &i);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	i = i + ft_strlen(str);
	free(str);
	va_end(arg);
	return (i);
}
