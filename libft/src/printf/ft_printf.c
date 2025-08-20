/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:30:41 by pnurmi            #+#    #+#             */
/*   Updated: 2025/05/10 14:54:02 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_gethelper(va_list *args, char *str, size_t *counter);
char	ft_putstr(char *str, size_t *counter);
void	ft_putchar(char c, size_t *counter);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	counter;

	counter = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_gethelper(&args, (char *)format, &counter);
		}
		else
		{
			ft_putchar(*format, &counter);
		}
		format++;
	}
	va_end(args);
	return (counter);
}

void	ft_gethelper(va_list *args, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar(va_arg(*args, int), counter);
	else if (*str == 's')
		ft_putstr(va_arg(*args, char *), counter);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr(va_arg(*args, int), counter);
	else if (*str == 'u')
		ft_putnbr_unsigned(va_arg(*args, unsigned int), counter);
	else if (*str == 'x' || *str == 'X')
	{
		if (*str == 'X')
			ft_puthex_up(va_arg(*args, unsigned int), counter);
		else
			ft_puthex_low(va_arg(*args, unsigned int), counter);
	}
	else if (*str == 'p')
		ft_putptr(va_arg(*args, void *), counter);
	else if (*str == '%')
		ft_putchar('%', counter);
	else
		ft_putstr("(error)", counter);
}

char	ft_putstr(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_putchar(*str++, counter);
	return (*counter);
}

void	ft_putchar(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}
