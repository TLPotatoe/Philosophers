/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_philos.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:53:51 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/26 17:29:11 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	setup_philos_mutex(t_philo_info *philos_data)
{
	size_t	index;

	if (pthread_mutex_init(&philos_data->print_mutex, NULL))
		return (FAIL);
	philos_data->philos = malloc(sizeof(t_philo) * philos_data->n_philo);
	if (!philos_data->philos)
	{
		pthread_mutex_destroy(&philos_data->print_mutex);
		return (FAIL);
	}
	index = 0;
	while (index < philos_data->n_philo)
	{
		if (pthread_mutex_init(&philos_data->philos[index].fork_mutex, NULL))
		{
			while (index--)
				pthread_mutex_destroy(&philos_data->philos[index].fork_mutex);
			free(philos_data->philos);
			pthread_mutex_destroy(&philos_data->print_mutex);
			return (FAIL);
		}
		philos_data->philos[index].id = index + 1;
		index++;
	}
	return (OK);
}

void	setup_philos_forks(t_philo_info *philos_data)
{
	size_t	index;

	if (philos_data->n_philo < 2)
		return ;
	index = 0;
	while (index < philos_data->n_philo - 1)
	{
		philos_data->philos[index].next_fork = &philos_data->philos[index
			+ 1].fork_mutex;
		index++;
	}
	philos_data->philos[philos_data->n_philo
		- 1].next_fork = &philos_data->philos[0].fork_mutex;
	return ;
}
