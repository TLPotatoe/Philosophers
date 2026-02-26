/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlamit <titouan.lamit@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 09:19:47 by tlamit            #+#    #+#             */
/*   Updated: 2026/02/26 17:48:27 by tlamit           ###   ########.fr       */
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

typedef struct s_philo
{
	size_t			id;
	pthread_t		thread;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	*next_fork;
	struct timeval	last_time_eat;
}					t_philo;

typedef struct s_philo_info
{
	size_t			n_philo;
	size_t			t_die;
	size_t			t_eat;
	size_t			t_sleep;
	size_t			eat_min;
	size_t			running;
	t_philo			*philos;
	pthread_mutex_t	print_mutex;
}					t_philo_info;

typedef struct s_thread_philo
{
	t_philo_info	philos_data;
	t_philo			philo;
}					t_thread_philo;

size_t				ft_atoi(const char *nptr);
size_t				setup_philos_mutex(t_philo_info *philos_data);
void				setup_philos_forks(t_philo_info *philos_data);
size_t				check_args(int argc, char **argv,
						t_philo_info *philos_data);
void				ft_print_status(t_philo_info *philos_data, size_t id,
						char *text);
unsigned long		elapsed_time(struct timeval start);
void				*philo_heart(void *args);

#endif
