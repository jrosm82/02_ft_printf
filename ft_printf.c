/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:14:43 by jrosmari          #+#    #+#             */
/*   Updated: 2023/02/04 10:08:56 by jrosmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(int c)
{
	return (write(1, &c, 1));	
}

static int	ft_putstr(char *s)
{	
	int	i;
	int	cnt;
		
	i = 0;
	cnt = 0;
	
	if (s == NULL)
	{
		cnt += ft_putstr("(null)");
		return (cnt);
	}        	
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

int count_hexdigits(uintptr_t value) {
    
    int count = 0;
    while (value > 0) 
    {
        value = value / 16;
        count++;
    }
    return count;
}

char	*print_p(uintptr_t value)
{
	static char	ptr[25];
	char	*hexlower = "0123456789abcdef";

	if (value == 0)	
		return ("(nil)");

	int i = count_hexdigits(value);
	ptr[0] = '0';
	ptr[1] = 'x';
	ptr[i + 2] = '\0';
	i--;
	while (i >= 0)
	{
		ptr[i + 2] = hexlower[value % 16];
		value = value / 16;
		i--;
	}
	return (ptr);
}

/*char	*print_p(uintptr_t value)
{
	static char	ptr[25];
	char	*hexlower = "0123456789abcdef";

	if (value == 0)	
		return ("(nil)");

	
	int i = count_hexdigits(value) + 2;
	if (i + 2 > 2)
	{
		ptr[0] = '0';
		ptr[1] = 'x';
		ptr[i] = '\0';
		i--;
		while (i + 2 >= 2)
		{
			ptr[i] = hexlower[value % 16];
			value = value / 16;
			i--;
		}
	}
	return (ptr);
}*/


char	*cnv_hex(unsigned int a, int low)
{
	static char	ptr[25];
	char	*hexlower = "0123456789abcdef";
	char	*hexupper = "0123456789ABCDEF";

	if (a == 0)
		return ("0");
		
	int i = count_hexdigits(a);
	if (i > 0)
	{
		ptr[i] = '\0';
		i--;

		if (low == 1)
		{
			while (i >= 0)
			{
				ptr[i] = hexlower[a % 16];
				a = a / 16;
				i--;
			}
		}
		else
		{
			while (i >= 0)
			{
				ptr[i] = hexupper[a % 16];
				a = a / 16;
				i--;
			}


		}	
		return (ptr);
	}
	else
		return (NULL);
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
	else if (c == 'p') // The void * pointer argument has to be printed in hexlowadecimal format
	{		
		
		prn_cnt += ft_putstr(print_p(va_arg(ap, uintptr_t)));
	}		
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
	else if (c == 'x') // Prints a number in hexlowadecimal (base 16) lowercase format	
		prn_cnt += ft_putstr(cnv_hex(va_arg(ap, uintptr_t), 1));	
	else if (c == 'X') // Prints a number in hexlowadecimal (base 16) uppercase format.
		prn_cnt += ft_putstr(cnv_hex(va_arg(ap, uintptr_t), 0));		
	else if (c == '%') // Prints a percent sign.
		prn_cnt += ft_putchar('%');
	else
	{
		prn_cnt += ft_putchar('%');
		prn_cnt += ft_putchar(c);	
	}	
	return (prn_cnt);
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
	int	pnt = -2147483648;

	int	*ptr = &pnt;

	   printf("%d",printf("*[%c]**[%d]**[%i]**[%s] rc[%%]***[%p]****[%x]**[%X]*=", 'A',pnt, pnt, "aa", ptr, 2147483647, 150378));
	printf("\n");
	printf("%d",ft_printf("*[%c]**[%d]**[%i]**[%s] rc[%%]***[%p]****[%x]**[%X]*=", 'A',pnt, pnt, "aa", ptr, 2147483647, 150378));
	printf("\n");

	char *p = NULL;
	   printf("%d", printf("****%c****[%s]****%s*****%s***=", '\0', p, "", " "));
	printf("\n");
	printf("%d", ft_printf("****%c****[%s]****%s*****%s***=", '\0', p, "", " "));	
	printf("\n");

	int	a = 0;
	   printf("%d", printf(" %p %p ", a, a));
	printf("\n");
	printf("%d", ft_printf(" %p %p ", a, a));
	printf("\n");

	return(0);
}*/
