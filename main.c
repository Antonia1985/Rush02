/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 09:45:00 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/28 20:12:39 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "header.h"

char	*file_contents = "numbers.dict";

char	*get_number(int argc, char **argv)
{
	if (argc == 2)
		return (ft_atoi(argv[1]));

	if (argc == 3)
		return (ft_atoi(argv[2]));
	return (NULL);
}
/*library	get_library(int argc, char **argv)
{
	//library

	//librarie == standard library
	if (argc == 3)
		//library = argv[1];
	return (library);	
}*/

void	ft_factorial(int i)
{
	char	*factorial;
	int	j;
	
	factorial = (char *)malloc(1 + (i * 3) + 1);
	factorial[0] = '1';
	j = 1;
	while (i > 0)
	{
		factorial[j] = '0';
		factorial[j + 1] = '0';
		factorial[j + 2] = '0';
		factorial[j + 3] = '\0';
		j += 3;
		i--;
	}
	factorial[j] = '\0';
	ft_print_value(factorial);
	free(factorial);
	factorial = NULL;
}

void	ft_resolve(char *buffer, int size)
{
	int	block;
	int	n_in_block;
	
	block = (size - 1) / 3;
	n_in_block = size % 3;
	if (n_in_block == 0)
		n_in_block = 3;
	if (block > 0)
	{
		ft_print_block(buffer, n_in_block); //put number before factorial
		if (buffer[0] != '0' || buffer[1] != '0' || buffer[2] != '0')
			ft_factorial(block); //put factorial
		ft_resolve(buffer + n_in_block, size - n_in_block); //recursive
	}
	else
		ft_print_block(buffer, n_in_block); //display last block
}

int	main(int argc, char **argv)
{
	char	*nbr;
	nbr = get_number(argc, argv);

	if (!nbr)
		write(1, "Error", 5);
	ft_resolve(nbr, ft_strlen(nbr));
	write(1, "\n", 1);
	return (0);
}
