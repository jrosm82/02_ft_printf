/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varstring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosmari <jrosmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:14:21 by jrosmari          #+#    #+#             */
/*   Updated: 2023/01/27 16:22:24 by jrosmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

void	testVar(char *str, ...)
{
	va_list	ap;
	int	pctCount;
	int	i;


	i = 0;
	pctCount = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
			pctCount++;
		i++;
	}
	i = 0;
	
	while (i < pctCount)
	{
		printf("Argument[%d] is [%s]\n",i, va_arg(ap, char *));
		i++;
	}
	va_end(ap);	
}

int	main(void)
{
	testVar("I am trying to print this % and this % aaaaaa %", "Hello", "World", "sdffsdfs");


	return (0);
}





