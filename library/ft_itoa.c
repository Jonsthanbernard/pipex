/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: you <Jonathan  Bernard>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 00:00:00 by you               #+#    #+#             */
/*   Updated: 2026/06/07 00:00:00 by you              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	pwr(int i, int j)
{
	int	result;

	result = 1;
	while (j > 0)
	{
		result *= i;
		j--;
	}
	return (result);
}

static int	get_len(int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, int n, int len, int neg)
{
	int	j;
	int	div;

	j = 0;
	while (j < len)
	{
		div = pwr(10, len - j - 1);
		str[j + neg] = '0' + ((n / div) % 10);
		j++;
	}
	str[j + neg] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		neg;

	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n *= -1;
	}
	len = get_len(n);
	str = malloc(len + neg + 1);
	if (!str)
		return (NULL);
	if (neg)
		str[0] = '-';
	fill_str(str, n, len, neg);
	return (str);
}
