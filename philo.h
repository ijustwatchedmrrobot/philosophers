/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:27:43 by sozdamar          #+#    #+#             */
/*   Updated: 2024/07/18 10:51:00 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
# include <pthread.h>
#include <unistd.h>

typedef struct s_philo
{
	int				philo_id;
	int				meals;
	unsigned long	last_eat;
	pthread_t		thread;
}					t_philo;

typedef struct s_data
{
	int				num_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_must_eat;
	int				is_philo_dead;
	int				thread_index;
	unsigned long	start_time;
	pthread_t		dead;
	pthread_mutex_t	mutex_util;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}					t_data;

//utilse
int				ft_atoi(const char *str);
unsigned long	get_time(void);
unsigned long	get_passed_time(unsigned long begin);
void			smart_sleep(int	time_pass);
void			destroy(t_data *data);


#endif