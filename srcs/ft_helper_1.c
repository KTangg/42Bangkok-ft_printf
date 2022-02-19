/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:42:49 by spoolpra          #+#    #+#             */
/*   Updated: 2022/02/18 16:42:49 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

void	*realloc_printf(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (ptr == NULL || old_size == 0)
		return (new_ptr);
	if (new_ptr)
		ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

void	*memjoin(void *ptr1, void *ptr2, size_t p1_size, size_t p2_size)
{
	void	*new_ptr;

	new_ptr = realloc_printf(ptr1, p1_size, p1_size + p2_size);
	if (new_ptr)
		ft_memcpy((new_ptr + p1_size), ptr2, p2_size);
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	return (new_ptr);
}
