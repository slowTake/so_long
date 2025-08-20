/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 13:27:52 by pnurmi            #+#    #+#             */
/*   Updated: 2025/07/24 11:28:37 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n, size_t *counter)
{
	long long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-', counter);
		num = -num;
	}
	if (num > 9)
	{
		ft_putnbr(num / 10, counter);
	}
	ft_putchar((num % 10) + '0', counter);
	return (*counter);
}

int	ft_putnbr_unsigned(unsigned long n, size_t *counter)
{
	if (n > 9)
	{
		ft_putnbr_unsigned(n / 10, counter);
	}
	ft_putchar((n % 10) + '0', counter);
	return (*counter);
}

int	ft_puthex_low(unsigned long n, size_t *counter)
{
	char	*hex;
	char	buffer[16];
	int		i;

	hex = "0123456789abcdef";
	i = 0;
	if (n == 0)
	{
		ft_putchar('0', counter);
		return (0);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		ft_putchar(buffer[--i], counter);
	}
	return (0);
}

int	ft_puthex_up(unsigned long n, size_t *counter)
{
	char	*hex;
	char	buffer[16];
	int		i;

	hex = "0123456789ABCDEF";
	i = 0;
	if (n == 0)
	{
		ft_putchar('0', counter);
		return (0);
	}
	while (n > 0)
	{
		buffer[i++] = hex[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		ft_putchar(buffer[--i], counter);
	}
	return (0);
}

int	ft_putptr(void *ptr, size_t *counter)
{
	void	*address;

	address = ptr;
	if (ptr == NULL)
		ft_putstr("(nil)", counter);
	else
	{
		ft_putstr("0x", counter);
		ft_puthex_low((unsigned long)address, counter);
	}
	return (*counter);
}
