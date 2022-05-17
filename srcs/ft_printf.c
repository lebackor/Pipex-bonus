/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:08:24 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/27 18:33:56 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_check_pourcent(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	if (c == 'p')
		ft_pointer(va_arg(args, unsigned long long), &i);
	if (c == 'd')
		i += ft_putnbr(va_arg(args, int));
	if (c == 'i')
		i += ft_putnbr(va_arg(args, int));
	if (c == 'u')
		i += ft_putnbr_u(va_arg(args, unsigned int));
	if (c == 'x')
		ft_print_hexa(va_arg(args, unsigned int), 0, &i);
	if (c == 'X')
		ft_print_hexa(va_arg(args, unsigned int), 1, &i);
	if (c == '%')
		i += ft_putchar('%');
	else
		return (i);
	return (i);
}

int	ft_putnbr_u(unsigned int nb)
{
	unsigned long	i;

	i = ft_count_nb(nb);
	if ((nb > 0 && nb <= 9))
	{
		nb += 48;
		write(1, &nb, 1);
	}
	else if (nb > 9)
	{
		ft_putnbr_u(nb / 10);
		ft_putnbr_u(nb % 10);
	}
	return (i);
}

long long	ft_count_nb(long long nb)
{
	long long	i;

	i = 0;
	if (nb < 0)
		i++;
	while (nb / 10)
	{
		nb /= 10;
		i++;
	}
	return (i +1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		k;

	i = 0;
	k = 0;
	va_start(args, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar(str[i]);
			i++;
			k++;
		}
		if (!str[i])
			return (k);
		else if (str[i] == '%' && ((str[i + 1] >= 'a' && str[i + 1] <= 'z')
				|| str[i + 1] == 'X' || str[i + 1] == '%'))
			k += ft_check_pourcent(str[++i], args);
		i++;
	}
	va_end(args);
	return (k);
}
