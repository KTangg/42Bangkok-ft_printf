/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:50:48 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/17 22:50:48 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	char	*str;
	va_list	arg;

	va_start(arg, format);
	str = create_str((char *)format, arg);
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	va_end(arg);
	return (1);
}
