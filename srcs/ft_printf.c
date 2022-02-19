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

static size_t	print_out(char *format, va_list *arg);

int	ft_printf(const char *format, ...)
{
	int		done;
	va_list	arg;
	va_list	*ptr;

	va_start(arg, format);
	ptr = &arg;
	done = print_out((char *)format, ptr);
	va_end(arg);
	return (done);
}

static void	*read_var(char *var_format, size_t *var_size, va_list *arg)
{
	char	c;
	void	*var;

	while (*var_format != '\0')
		c = *var_format++;
	if (c == 'c')
		var = get_char(arg, var_size);
	else if (c == 's')
		var = get_str(arg, var_size);
	else if (c == 'p')
		var = get_ptr(arg, var_size);
	else if (c == 'd')
		var = get_dec(arg, var_size);
	else if (c == 'i')
		var = get_int(arg, var_size);
	else if (c == 'u')
		var = get_ud(arg, var_size);
	else if (c == 'x')
		var = get_hex(arg, var_size, 0);
	else if (c == 'X')
		var = get_hex(arg, var_size, 1);
	else if (c == '%')
		var = get_percent(var_size);
	return (var);
}

static void	*append_variable(void *buffer, size_t *size, char **format, va_list *arg)
{
	void	*var;
	char	*var_format;
	size_t	var_size;

	var_size = 0;
	var_format = get_format(format);
	if (!var_format)
		return (NULL);
	var = read_var(var_format, &var_size, arg);
	/*var = extend_format(var_format, var, &var_size);*/
	if (!var)
		return (NULL);
	buffer = memjoin(buffer, var, *size, var_size);
	*size = *size + var_size;
	return (buffer);
}

static void	*make_buffer(void *buffer, char *format, va_list *arg, size_t *size)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			buffer = append_variable(buffer, size, &format, arg);
			if (!buffer)
				return (NULL);
		}
		else
		{
			buffer = realloc_printf(buffer, *size, *size + 1);
			if (!buffer)
				return (NULL);
			((unsigned char *)buffer)[*size] = (unsigned char)*format;
			*size = *size + 1;
			format++;
		}
	}
	return (buffer);
}

static size_t	print_out(char *format, va_list *arg)
{
	size_t	size;
	void	*buffer;

	size = 0;
	buffer = NULL;
	buffer = make_buffer(buffer, format, arg, &size);
	if (!buffer)
		return (0);
	write(1, buffer, size);
	return (size);
}
