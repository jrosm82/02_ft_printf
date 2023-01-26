/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vartest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:14:21 by jrosmari          #+#    #+#             */
/*   Updated: 2023/01/26 18:26:25 by jrosmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int	testVar(int count, ...)
{
	va_list	ap;
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	va_start(ap, count);

	while (i < count)
	{
		sum = sum + va_arg(ap, int);
		i++;
	}

	va_end(ap);
	return (sum);
}

int	main(void)
{
	printf("Sum of the numbers %d \n", testVar(3,1,4,1));


	return (0);
}





