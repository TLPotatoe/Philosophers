/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_philos_mutex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:53:51 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/23 19:46:28 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	setup_philos_mutex(t_philo_info *philo_data)
{
	size_t	index;

	if (pthread_mutex_init(&philo_data->print_mutex, NULL))
		return (FAIL);
	philo_data->philos = malloc(sizeof(t_philo) * philo_data->n_philo);
	if (!philo_data->philos)
	{
		pthread_mutex_destroy(&philo_data->print_mutex);
		return (FAIL);
	}
	index = 0;
	while (index < philo_data->n_philo)
	{
		if (pthread_mutex_init(&philo_data->philos[index].fork_mutex, NULL))
		{
			while (index--)
				pthread_mutex_destroy(&philo_data->philos[index].fork_mutex);
			free(philo_data->philos);
			pthread_mutex_destroy(&philo_data->print_mutex);
			return (FAIL);
		}
		philo_data->philos[index].id = index + 1;
	}
	return (OK);
}
