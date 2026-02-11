/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:58:14 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/11 19:01:00 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t ft_strlen(char *str)
{
	size_t index ;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
		index++;
	return (index);
}

void ft_perror(char *error)
{
	write(2, error, ft_strlen(error));
}
