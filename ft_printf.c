/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosmari <jrosmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:14:43 by jrosmari          #+#    #+#             */
/*   Updated: 2023/01/28 11:10:46 by jrosmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

int	pnt_decide(char c, va_list ap)
{
	int	prn_cnt;


	prn_cnt = 0;
	if (c == 'c') // Prints a single character.
		prn_cnt += ft_putchar(va_arg(ap, int));
	else if (c == 's') // Prints a string (as defined by the common C convention).
		prn_cnt += ft_putstr(va_arg(ap, char *));
	else if (c == 'p') // The void * pointer argument has to be printed in hexadecimal format
		c = c;
	else if (c == 'd') // Prints a decimal (base 10) number.
		c = c;
	else if (c == 'i') // Prints an integer in base 10.
		c = c;
	else if (c == 'u') // Prints an unsigned decimal (base 10) number.
		c = c;
	else if (c == 'x') // Prints a number in hexadecimal (base 16) lowercase format
		c = c;
	else if (c == 'X') // Prints a number in hexadecimal (base 16) uppercase format.
		c = c;
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

#include <stdio.h>

int	main(void)
{
	printf("%d",ft_printf("*%c*%s%r rc%%=", 'A',"aa"));
	printf("\n");
	printf("\n");
	printf("%d",printf("*%c*%s%r rc%%=", 'A', "aa"));
	printf("\n");
	return(0);
}