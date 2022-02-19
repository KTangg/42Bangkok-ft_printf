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

void	*get_char(va_list *arg, size_t *var_size)
{
	int		c;
	void	*var;

	*var_size = 1;
	c = va_arg(*arg, int);
	var = malloc(sizeof(unsigned char) * 1);
	if (var)
		var = ft_memcpy(var, &c, 1);
	return (var);
}

static void	*null_str(size_t *var_size)
{
	char	*null;
	void	*var;

	null = "(null)";
	var = malloc(sizeof(char) * 6);
	*var_size = 6;
	if (var)
		var = ft_memcpy(var, null, 6);
	return (var);
}

void	*get_str(va_list *arg, size_t *var_size)
{
	void	*var;
	char	*str;
	size_t	len;

	str = va_arg(*arg, char *);
	if (!str)
		return (null_str(var_size));
	len = ft_strlen(str);
	*var_size = len;
	var = malloc(len);
	if (var)
		var = ft_memcpy(var, str, len);
	return (var);
}

void	*get_dec(va_list *arg, size_t *var_size)
{
	int		i;
	char	*str;
	void	*var;

	i = va_arg(*arg, int);
	str = ft_itoa(i);
	if (!str)
		return (NULL);
	*var_size = ft_strlen(str);
	var = malloc(var_size);
	if (var)
		var = ft_memcpy(var, str, *var_size);
	free(str);
	return (var);
}

void	*get_int(va_list *arg, size_t *var_size)
{
	int		i;
	char	*str;
	void	*var;

	i = va_arg(*arg, int);
	str = ft_itoa(i);
	if (!str)
		return (NULL);
	*var_size = ft_strlen(str);
	var = malloc(var_size);
	if (var)
		var = ft_memcpy(var, str, *var_size);
	free(str);
	return (var);
}
