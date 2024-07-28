/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:44:02 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/28 20:26:42 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_print_value(char *str)
{
	char *value;

	value = find_value_by_key(read_file(file_contents), str);
	write(1, value, ft_strlen(value));
}

void	ft_ones(char *buffer)
{
	char	*ones_buf;

	ones_buf = (char *)malloc(2);
	ones_buf[0] = buffer[0];
	ones_buf[1] = '\0';
	ft_print_value(ones_buf);
	free (ones_buf);
	ones_buf = NULL;
}

void	ft_tens(char *buffer)
{
	char	*tens_buf;

	tens_buf = (char *)malloc(3);
	tens_buf[0] = buffer[0];
	tens_buf[1] = buffer[1];
	tens_buf[2] = '\0';
	if (tens_buf[0] < '2' || tens_buf[1] == '0')
		ft_print_value(tens_buf);
	else
	{
		tens_buf[0] = buffer[0];
		tens_buf[1] = '0';
		ft_print_value(tens_buf);
		tens_buf[0] = buffer[1];
		tens_buf[1] = '\0';
		ft_print_value(tens_buf);
	}
	free (tens_buf);
	tens_buf = NULL;
}

void	ft_hundreds(char *buffer)
{
	char	*hundreds_buf;

	hundreds_buf = (char *)malloc(4);
	hundreds_buf[0] = buffer[0];
	hundreds_buf[1] = '\0';
	ft_print_value(hundreds_buf);
	ft_print_value("100");
	hundreds_buf[1] = buffer[1];
	hundreds_buf[2] = buffer[2];
	if (hundreds_buf[1] != '0')
		ft_tens(buffer + 1);
	if (hundreds_buf[1] == '0' && hundreds_buf[2] != '0')
		ft_ones(buffer + 2);
	free (hundreds_buf);
	hundreds_buf = NULL;
}

void	ft_print_block(char *buffer, int n_in_block)
{
	int	i;

	i = 0;
	if (n_in_block > 1)
	{
		while (i < 3 && *buffer == '0') //skip 0's
		{	
			i++;
			buffer++;
			n_in_block--;
		}
	}
	if (n_in_block == 1)
		ft_ones(buffer);
	if (n_in_block == 2)
		ft_tens(buffer);
	if (n_in_block == 3)
		ft_hundreds(buffer);
}