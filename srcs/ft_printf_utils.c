/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:09:29 by lebackor          #+#    #+#             */
/*   Updated: 2021/12/27 18:30:26 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_put_hexa_min(unsigned int nb)
{
	if (nb == 10)
		ft_putchar('a');
	else if (nb == 11)
		ft_putchar('b');
	else if (nb == 12)
		ft_putchar('c');
	else if (nb == 13)
		ft_putchar('d');
	else if (nb == 14)
		ft_putchar('e');
	else if (nb == 15)
		ft_putchar('f');
	return (1);
}

int	ft_put_hexa_maj(unsigned int nb)
{
	if (nb == 10)
		ft_putchar('A');
	else if (nb == 11)
		ft_putchar('B');
	else if (nb == 12)
		ft_putchar('C');
	else if (nb == 13)
		ft_putchar('D');
	else if (nb == 14)
		ft_putchar('E');
	else if (nb == 15)
		ft_putchar('F');
	return (1);
}

int	ft_print_hexa(unsigned long long nb, int a, int *count)
{
	if (nb > 0 && nb < 16)
	{
		if (nb > 0 && nb <= 9)
			ft_putchar(nb + 48);
		else
		{
			if (a == 0)
				ft_put_hexa_min(nb);
			else if (a == 1)
				ft_put_hexa_maj(nb);
		}
		(*count)++;
	}
	else
	{
		ft_print_hexa(nb / 16, a, count);
		ft_print_hexa(nb % 16, a, count);
	}
	return (*count);
}

int	ft_pointer(unsigned long long nb, int *count)
{
	(*count) += 2;
	ft_putstr("0x");
	ft_print_hexa(nb, 0, count);
	return (*count);
}
/*
   int ft_putnbr_count(int nb)
   {
   int i;

   i = 0;
   ft_putnbr(nb);
   i = ft_strlen(ft_itoa(nb));
// printf("\nPUTNBR COUNT = %d\n", i);
return (i);
}*/
