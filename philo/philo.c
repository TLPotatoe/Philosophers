/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:09:30 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/26 17:38:58 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	start_all(t_philo_info *philos_data)
{
	size_t			index;
	t_thread_philo	selector;

	selector.philos_data = *philos_data;
	index = 0;
	while (index < philos_data->n_philo)
	{
		selector.philo = (philos_data->philos[index]);
		pthread_create(&selector.philo.thread, NULL, philo_heart, &selector);
		index++;
	}
}

int	main(int argc, char **argv)
{
	static t_philo_info	philos_data = {0};

	if (argc != 5 && argc != 6)
	{
		printf("number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return (1);
	}
	if (check_args(argc, argv, &philos_data) == FAIL)
		return (1);
	if (setup_philos_mutex(&philos_data) == FAIL)
		return (1);
	setup_philos_forks(&philos_data);
	start_all(&philos_data);
	return (0);
}
