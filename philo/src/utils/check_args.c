/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:34:39 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/26 17:12:22 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// 1 number_of_philosophers
// 2 time_to_die
// 3 time_to_eat
// 4 time_to_sleep
// 5 [number_of_times_each_philosopher_must_eat] optional

size_t	check_args(int argc, char **argv, t_philo_info *philos_data)
{
	int	index;

	index = 1;
	while (index < argc)
		if (!ft_atoi(argv[index++]))
			return (FAIL);
	if (argc == 6 && !ft_atoi(argv[index]))
		return (FAIL);
	philos_data->n_philo = ft_atoi(argv[1]);
	philos_data->t_die = ft_atoi(argv[2]);
	philos_data->t_eat = ft_atoi(argv[3]);
	philos_data->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philos_data->eat_min = ft_atoi(argv[5]);
	return (OK);
}
