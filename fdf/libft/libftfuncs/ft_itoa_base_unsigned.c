/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edal-san <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 23:03:48 by edal-san          #+#    #+#             */
/*   Updated: 2016/11/09 17:24:48 by edal-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	int_len(unsigned long long int n)
{
	size_t		len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void		ft_reverse(char *s)
{
	char		*start;
	char		*end;
	char		*cpy;
	char		tmp;

	cpy = s;
	start = cpy;
	while (*cpy)
		cpy++;
	end = cpy - 1;
	while (start < end)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

static char		*zero_case(char *s)
{
	char		*cpy;

	cpy = s;
	*cpy++ = '0';
	*cpy = '\0';
	return (s);
}

char			*ft_itoa_base_unsigned(unsigned long long int n, int base)
{
	char		*s;
	char		digits[16];
	char		*cpy;

	ft_strcpy(digits, "0123456789abcdef");
	if (!(s = (char*)malloc((sizeof(char) * int_len(n)) + 2)))
		return (NULL);
	if (n == 0 || n == -0)
		return (zero_case(s));	
	cpy = s;
	while (n)
	{
		*cpy++ = digits[(n % base)];
		n /= base;
	}
	*cpy = '\0';
	ft_reverse(s);
	return (s);
}
