/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:31:34 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/18 02:31:34 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:50:20 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/18 01:50:20 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_char(va_list *arg)
{
	char	c;
	char	*str;

	c = va_arg(*arg, int);
	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*get_str(va_list *arg)
{
	char	*s;
	char	*str;
	size_t	len;

	s = va_arg(*arg, char *);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

char	*get_ptr(va_list *arg)
{
	(void)arg;
	return (NULL);
}

char	*get_dec(va_list *arg)
{
	int	i;
	char	*str;

	i = va_arg(*arg, int);
	str = ft_itoa(i);
	return (str);
}

char	*get_int(va_list *arg)
{
	int	i;
	char	*str;

	i = va_arg(*arg, int);
	str = ft_itoa(i);
	return (str);
}
