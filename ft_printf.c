/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:58:12 by csenand           #+#    #+#             */
/*   Updated: 2022/11/16 11:26:54 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 	DESCRIPTION
** 	A function that prints a variable number of arguments and print the data
**	per the given arguments.
** 	
**	PARAMETERS
**	form : a char that defines the type a data the user wants to print out :
**			• %c Prints a single character.
**			• %s Prints a string (as defined by the common C convention).
**			• %p The void * pointer argument has to be printed in hexadecimal format.
**			• %d Prints a decimal (base 10) number.
**			• %i Prints an integer in base 10.
**			• %u Prints an unsigned decimal (base 10) number.
**			• %x Prints a number in hexadecimal (base 16) lowercase format.
**			• %X Prints a number in hexadecimal (base 16) uppercase format.
**			• %% Prints a percent sign.
**
**	RETURN VALUE
**	An int which is the nbr of characters in the output
*/

#include "ft_printf.h"

static	int	ft_print_data(va_list list, char c);

int	ft_printf(const	char *form, ...)
{
	va_list	arg;
	int		i;
	int		output;

	if (!form)
		return (0);
	va_start(arg, form);
	i = 0;
	output = 0;
	while (form[i])
	{
		if (form[i] != '%')
			output += ft_putchar_fd(form[i], 1);
		else
		{
			i++;
			output += ft_print_data(arg, form[i]);
		}
		i++;
	}
	va_end(arg);
	return (output);
}

static	int	ft_print_data(va_list list, char c)
{
	char	*s;

	if (c == '%')
		return (ft_putchar_fd('%', 1));
	else if (c == 'c')
		return (ft_putchar_fd(va_arg (list, int), 1));
	else if (c == 's')
	{
		s = va_arg (list, char *);
		if (!s)
			return (ft_putstr_fd("(null)", 1));
		return (ft_putstr_fd(s, 1));
	}
	else if (c == 'i' || c == 'd')
		return (ft_putnbr_fd(va_arg (list, int), 1));
	else if (c == 'u')
		return (ft_print_u(va_arg (list, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_hex(va_arg (list, unsigned int), c));
	else if (c == 'p')
		return (ft_print_ptr(va_arg (list, uintptr_t)));
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	ft_printf("%d\n", ft_printf(NULL));
	ft_printf("%d\n", ft_printf("Bonjour %s\n", NULL));
	
	ft_printf("%d\n", ft_printf("Bonjour %s\n", "toi"));
	printf("%d\n", printf("Bonjour %s\n", "toi"));
	
	ft_printf("%d\n", ft_printf("Bonjour %X\n", 56432867));
	printf("%d\n", printf("Bonjour %X\n", 56432867));
	
	ft_printf("%d\n", ft_printf("Bonjour %u\n", -99));
	printf("%d\n", printf("Bonjour %u\n", -99));
}
*/