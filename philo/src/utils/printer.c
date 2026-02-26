/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:31:27 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/26 17:13:20 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	elapsed_time(struct timeval start)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (((current.tv_sec - start.tv_sec) * 1000) + ((current.tv_usec
				- start.tv_usec) / 1000));
}

void	ft_print_status(t_philo_info *philos_data, size_t id, char *text)
{
	static struct timeval	start;
	static size_t			start_ready = 0;

	if (!start_ready)
	{
		gettimeofday(&start, NULL);
		start_ready++;
	}
	pthread_mutex_lock(&philos_data->print_mutex);
	printf("[%lu] %zu %s\n", elapsed_time(start), id, text);
	pthread_mutex_unlock(&philos_data->print_mutex);
}
