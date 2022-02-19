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

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
char	*ft_itoa(int n);
char	*get_percent(void);
char	*get_ud(va_list *arg);
char	*get_ptr(va_list *arg);
char	*get_str(va_list *arg);
char	*get_int(va_list *arg);
char	*get_dec(va_list *arg);
char	*get_hexu(va_list *arg);
char	*get_hexl(va_list *arg);
char	*get_char(va_list *arg, int *i);
char	*var_to_str(char c, va_list *arg, int *i);
char	*create_str(char *format, va_list *arg, int *i);
char	*ft_strjoin(const char *s1, const char *s2);
char	*append_str(char *str1, char *start, size_t n);
char	*make_str(char *str, char *format, va_list *arg, int *i);
char	*append_variable(char *str1, char c, va_list *arg, int *i);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif
