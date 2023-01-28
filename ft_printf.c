/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosmari <jrosmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:14:43 by jrosmari          #+#    #+#             */
/*   Updated: 2023/01/27 16:57:06 by jrosmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);	
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int	i;

	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				ft_putchar(va_arg(ap, int));
			}
			else if (str[i] == '%')
				ft_putchar('%');
			else
			{
				i--;
				ft_putchar(str[i]);
			}
		}
		else	
			ft_putchar(str[i]);			
		i++;
	}
	ft_putchar('\n');	
	va_end(ap);
	return (0);
}

#include <stdio.h>

int	main(void)
{
	ft_printf("**%c***%d*****%c*****%c*******%a***%c****%*********%c", 'H', 'e', 'l', 'l', 'o');
	printf("\n");
	printf("%% %                             choj",'a');
	printf("\n");
	return(0);
}