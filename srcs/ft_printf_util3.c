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

#include "libft.h"
#include "libftprintf.h"

char	*get_ud(va_list *arg)
{
	(void)arg;
	return (0);
}

char	*get_hexl(va_list *arg)
{
	(void)arg;
	return (0);
}

char	*get_hexu(va_list *arg)
{
	(void)arg;
	return (0);
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
