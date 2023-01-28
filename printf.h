/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrosmari <jrosmari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:11:51 by jrosmari          #+#    #+#             */
/*   Updated: 2023/01/27 18:07:42 by jrosmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_print                       
{                        
      va_list  args;    # arg to print out                    
      int   wdt;        # width                
      int   prc;        # precision              
      int   zero;       # zero padding               
      int   pnt;        # .     
      int   dash;       # -               
      int   tl;         # total_length (return value)              
      int   sign;       # pos or neg number               
      int   is_zero;    # is number zero                 
      int   perc;       # %               
      int   sp;         # space flag ' '            
}    t_print;

int	ft_printf(const char *, ...);

#endif