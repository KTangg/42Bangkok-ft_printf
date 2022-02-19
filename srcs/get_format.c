/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:10:24 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/19 22:10:24 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*get_format(char **format)
{
	char	*var_format;

	var_format = (char *)malloc(sizeof(char) * 2);
	var_format[0] = *((*format) + 1);
	var_format[1] = '\0';
	*format = *format + 1;
	return (var_format);
}
