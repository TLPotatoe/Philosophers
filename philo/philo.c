/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:09:30 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/13 15:00:08 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	static t_philo_info	philo_data = {0};

	if (argc != 5 && argc != 6)
		return (1);
	if (check_args(argc, argv, &philo_data))
		return (1);
	if (!setup_philos_mutex(&philo_data))
		return (1);
	return (0);
}
