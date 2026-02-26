/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_heart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 15:17:38 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/26 17:47:16 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static size_t	is_philo_dead(t_philo_info *philos_data, t_philo *philo)
{
	if (elapsed_time(philo->last_time_eat) > philos_data->t_die)
		return (1);
	return (0);
}

void	*philo_heart(void *args)
{
	t_thread_philo	*infos;

	infos = (t_thread_philo *)args;
	while (!is_philo_dead(&infos->philos_data, &infos->philo))
	{
		ft_print_status(&infos->philos_data, &infos->philo.id, "is thinking");
		usleep(infos->philos_data.t_sleep);
		pthread_mutex_lock(&infos->philo.fork_mutex);
		pthread_mutex_lock(&infos->philo.next_fork);
		is_philo_dead(&infos->philos_data, &infos->philo);
		ft_print_status(&infos->philos_data, &infos->philo.id, "is eating");
		usleep(&infos->philos_data.t_eat);
		pthread_mutex_unlock(&infos->philo.fork_mutex);
		pthread_mutex_unlock(&infos->philo.next_fork);
		is_philo_dead(&infos->philos_data, &infos->philo);
		ft_print_status(&infos->philos_data, &infos->philo.id, "is sleeping");
		usleep(&infos->philos_data.t_sleep);
	}
	return (NULL);
}
