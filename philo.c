/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:47:49 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/11 19:04:29 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

#include "philo.h"

int main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		ft_perror("Error\nInvalid number of arguments: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
		return 0;
	}
	printf("%s", av[2]);
}
