/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:55:14 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/17 22:55:14 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*var_to_str(char c, va_list *arg)
{
	char	*str2;

	if (c == 'c')
		str2 = get_char(arg);
	else if (c == 's')
		str2 = get_str(arg);
	else if (c == 'p')
		str2 = get_ptr(arg);
	else if (c == 'd')
		str2 = get_dec(arg);
	else if (c == 'i')
		str2 = get_int(arg);
	else if (c == 'u')
		str2 = get_ud(arg);
	else if (c == 'x')
		str2 = get_hexl(arg);
	else if (c == 'X')
		str2 = get_hexu(arg);
	else if (c == '%')
		str2 = get_percent();
	else
		return (NULL);
	if (!str2)
		return (NULL);
	return (str2);
}

char	*append_str(char *str1, char *start, size_t n)
{
	char	*tmp;
	char	*str2;

	str2 = (char *)malloc(sizeof(char) * (n + 1));
	if (!str2)
	{
		free(str1);
		return (NULL);
	}
	ft_strlcpy(str2, start, n + 1);
	tmp = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*append_variable(char *str1, char c, va_list *arg)
{
	char	*tmp;
	char	*str2;

	str2 = var_to_str(c, arg);
	if (!str2)
		return (NULL);
	tmp = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (tmp);
}

char	*make_str(char *str, char *format, va_list *arg)
{
	int		i;
	char	*start;

	start = (char *)format;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			str = append_str(str, start, &format[i] - start);
			if (!str)
				return (NULL);
			start = &format[i] + 2;
			str = append_variable(str, format[i++ + 1], arg);
			if (!str)
				return (NULL);
		}
		i++;
	}
	str = append_str(str, start, &format[i] - start);
	if (!str)
		return (NULL);
	return (str);
}

char	*create_str(char *format, va_list arg)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	str = make_str(str, format, &arg);
	if (!str)
		return (NULL);
	return (str);
}
