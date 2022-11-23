/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csenand <csenand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:46:05 by csenand           #+#    #+#             */
/*   Updated: 2022/11/16 11:26:44 by csenand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/*		ft_len_ft		*/
size_t	ft_strlen(const char *s);
int		ft_num_length(long nb);
int		ft_hex_length(long nb);
int		ft_ptr_len(uintptr_t num);

/*		ft_print_ft		*/
int		ft_printf(const	char *form, ...);
int		ft_print_u(long n);
int		ft_print_hex(unsigned int num, const char format);
int		ft_print_ptr(uintptr_t ptr);

/*		ft_put_ft		*/
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
void	ft_put_hex(unsigned int num, const char form_x);
void	ft_put_ptr(uintptr_t num);

#endif