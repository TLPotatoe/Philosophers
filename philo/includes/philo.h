/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:19:47 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/13 11:50:02 by tlamit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef enum e_ret_code
{
	OK = 0,
	FAIL = 1
}					t_ret_code;

typedef enum e_mode
{
	SLEEPING = 0,
	THINKING = 1,
	EATING = 2
}					t_mode;

typedef struct s_philo
{
	size_t			id;
	size_t			alive;
	t_mode			state;
	pthread_t		thread;
	pthread_mutex_t	fork_mutex;
	struct s_philo	*next_philo;
	struct s_philo	*prev_philo;
}					t_philo;

typedef struct s_philo_info
{
	size_t			n_philo;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	size_t			eat_min;
	t_philo			*philos;
	pthread_mutex_t	print_mutex;
}					t_philo_info;

size_t				ft_atoi(const char *nptr);
size_t				setup_philos_mutex(t_philo_info *philo_data);
size_t				check_args(int argc, char **argv, t_philo_info *philo_data);
#endif
