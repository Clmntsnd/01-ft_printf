/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loulou <loulou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:12:12 by csenand           #+#    #+#             */
/*   Updated: 2023/07/14 10:48:15 by loulou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

/*
**	int	ft_print_u(long n);
**	int	ft_print_hex(unsigned int num, const char format);
**	int	ft_print_ptr(uintptr_t ptr);
*/

/*
**	ft_print_u.c
**	
** 	DESCRIPTION
**	itoa based function.
** 	Allocates (with malloc(3)) and returns a string representing 
**	the unisgned integer received as an argument.
**	
**	PARAMETERS
**	n: The unisgned integer to convert.
**	
**	RETURN VALUE
**	The nb of char in the string representing the unsigned integer.
**	NULL if the allocation fails.
*/

int	ft_print_u(long n)
{
	int		i;
	char	*num_c;
	int		size;
	int		size_r;

	i = 0;
	size = ft_num_length(n);
	size_r = size;
	num_c = malloc(sizeof(char) * (size + 1));
	if (!num_c)
		return (0);
	num_c[size] = '\0';
	while (size != i)
	{
		size--;
		num_c[size] = n % 10 + '0';
		n /= 10;
	}
	while (i < size_r)
		ft_putchar_fd(num_c[i++], 1);
	free(num_c);
	return (size_r);
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_length(num));
}

int	ft_print_ptr(uintptr_t ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
	{
		ft_put_ptr(ptr);
		print_length += ft_ptr_len(ptr);
	}
	return (print_length);
}
