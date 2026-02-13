/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:37:57 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/13 09:41:07 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atoi(const char *nptr)
{
	int result;

	if (!nptr)
		return (-1);
	result = 0;
	while ((9 <= *nptr && *nptr <= 13) || *nptr == 32)
		nptr++;
	while ('0' <= (*nptr) && (*nptr) <= '9')
		result = result * 10 + *nptr++ - '0';
	return (result);
}