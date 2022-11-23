/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:59:44 by csenand           #+#    #+#             */
/*   Updated: 2022/11/22 11:53:58 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	int		ft_putchar_fd(char c, int fd);
**	int		ft_putstr_fd(char *s, int fd);
**	int		ft_putnbr_fd(int n, int fd);
**	void	ft_put_hex(unsigned int num, const char form_x);
**	void	ft_put_ptr(uintptr_t num);
*/

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	if (s)
		return (write(fd, s, ft_strlen(s)));
	return (0);
}

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		temp;

	temp = n;
	if (n == -2147483648)
	{
		return (write(fd, "-2147483648", 11));
	}
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		n %= 10;
	}
	c = n + 48;
	write(fd, &c, 1);
	return (ft_num_length(temp));
}

void	ft_put_hex(unsigned int num, const char form_x)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, form_x);
		ft_put_hex(num % 16, form_x);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (form_x == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (form_x == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}
