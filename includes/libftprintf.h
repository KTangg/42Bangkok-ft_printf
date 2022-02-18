/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:11:17 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/17 22:41:47 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*get_percent(void);
char	*get_ud(va_list *arg);
char	*get_ptr(va_list *arg);
char	*get_str(va_list *arg);
char	*get_int(va_list *arg);
char	*get_dec(va_list *arg);
char	*get_hexu(va_list *arg);
char	*get_hexl(va_list *arg);
char	*get_char(va_list *arg);
char	*var_to_str(char c, va_list *arg);
char	*create_str(char *format, va_list *arg);
char	*append_str(char *str1, char *start, size_t n);
char	*append_variable(char *str1, char c, va_list *arg);
char	*make_str(char *str, char *format, va_list *arg);

#endif
