/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <joao-alm@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 08:29:04 by joao-alm          #+#    #+#             */
/*   Updated: 2024/07/28 17:46:11 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//atoi.c
char	*ft_atoi(char *str);
//print.c
void	ft_print_block(char *buffer, int n_in_block);
void	ft_print_value(char *str);
//helpers.c
int	ft_strlen(char *str);
//dictionary.c
char *read_file(char *filename);
char *find_value_by_key(char *contents, char *key);

//library
extern char	*file_contents;

#endif