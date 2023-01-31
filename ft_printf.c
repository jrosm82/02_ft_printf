/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosmari <jrosmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:14:43 by jrosmari          #+#    #+#             */
/*   Updated: 2023/01/28 16:02:23 by jrosmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));	
}

int	ft_putstr(char *s)
{	
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		cnt += ft_putchar(s[i]);
		i++;
	}
	return (cnt);
}

static int	int_len(int nbr)
{
	int	pos;

	pos = 0;
	if (nbr == -2147483648)
		return (11);
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		pos++;
		nbr = nbr * -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		pos++;
	}
	return (pos);
}

static int	uint_len(unsigned int nbr)
{
	int	pos;

	pos = 0;

	if (nbr == 0)
		return (1);	
	while (nbr > 0)
	{
		nbr = nbr / 10;
		pos++;
	}
	return (pos);
}

void	ft_putuint(unsigned int n)
{
	if (n >= 10)
	{
		ft_putuint(n / 10);
		ft_putuint(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void	ft_putint(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		ft_putint(n / 10);
		ft_putint(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int	pnt_decide(char c, va_list ap)
{
	int	prn_cnt;
	int	n;
	int	un;

	prn_cnt = 0;
	if (c == 'c') // Prints a single character.
		prn_cnt += ft_putchar(va_arg(ap, int));
	else if (c == 's') // Prints a string (as defined by the common C convention).
		prn_cnt += ft_putstr(va_arg(ap, char *));
	else if (c == 'p') // The void * pointer argument has to be printed in hexadecimal format
	{}		
	else if (c == 'i' || c == 'd') // Prints an integer in base 10.
	{
		n = va_arg(ap, int);
		prn_cnt += int_len(n);
		ft_putint(n);
	}
	else if (c == 'u') // Prints an unsigned decimal (base 10) number.
	{
		un = va_arg(ap,unsigned int);
		prn_cnt += uint_len(un);
		ft_putuint(un);
	}	
	else if (c == 'x') // Prints a number in hexadecimal (base 16) lowercase format	
	{}	
	else if (c == 'X') // Prints a number in hexadecimal (base 16) uppercase format.
	{}		
	else if (c == '%') // Prints a percent sign.
		prn_cnt += ft_putchar('%');
	else
	{
		prn_cnt += ft_putchar('%');
		prn_cnt += ft_putchar(c);	
	}	
	return (prn_cnt);

//cspdiuxX%

}



int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	i;
	int	prn_cnt;

	prn_cnt = 0;
	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			prn_cnt += pnt_decide(str[i], ap);			
		}
		else
		{
			prn_cnt += ft_putchar(str[i]);
		}

		i++;		
	}		
	va_end(ap);
	return (prn_cnt);
}
/*
#include <stdio.h>

int	main(void)
{
	int	pnt = -1;

	int	*ptr = &pnt;
	
	printf("%d",ft_printf("%u=",-1));
	printf("\n");
	printf("%d",printf("%u=", -1));
	printf("\n");
	//printf("%d",printf("[%p]=", ptr));
	
	printf("\n");


	return(0);
}*/
