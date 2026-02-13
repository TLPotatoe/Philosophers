/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:34:39 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/13 10:50:26 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1 number_of_philosophers
// 2 time_to_die
// 3 time_to_eat
// 4 time_to_sleep
// 5 [number_of_times_each_philosopher_must_eat] optional

size_t	check_args(int argc, char **argv, t_philo_info *philo_data)
{
	int	index;

	index = 1;
	while (index < argc)
		if (!ft_atoi(argv[index]))
			return (1);
	if (argc == 6 && !ft_atoi(argv[index]))
		return (1);
	philo_data->n_philo = ft_atoi(argv[1]);
	philo_data->t_die = ft_atoi(argv[2]);
	philo_data->t_eat = ft_atoi(argv[3]);
	philo_data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_data->eat_min = ft_atoi(argv[5]);
	return (0);
}
