/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 22:11:17 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/18 19:10:38 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
int		ft_isdigit(int c);
int		valid_flag(char *str);
int		ft_atoi(const char *nptr);
char	*ft_itoa(long n);
char	*get_format(char **format);
char	*ft_strjoin(const char *s1, const char *s2);
char	*extend_format(char *var_format, void *var, size_t *var_size);
void	*get_percent(size_t *var_size);
void	*get_ud(va_list *arg, size_t *var_size);
void	*get_str(va_list *arg, size_t *var_size);
void	*get_dec(va_list *arg, size_t *var_size);
void	*get_int(va_list *arg, size_t *var_size);
void	*get_ptr(va_list *arg, size_t *var_size);
void	*get_char(va_list *arg, size_t *var_size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*get_hex(va_list *arg, size_t *var_size, int mode);
void	*realloc_printf(void *ptr, size_t old_size, size_t new_size);
void	*memjoin(void *ptr1, void *ptr2, size_t p1_size, size_t p2_size);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
