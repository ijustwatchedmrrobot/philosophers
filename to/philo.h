/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:27:43 by sozdamar          #+#    #+#             */
/*   Updated: 2024/07/18 12:00:22 by sozdamar         ###   ########.fr       */
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
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				num_eat;
	int				is_philo_dead;
	int				thread_index;
	unsigned long	start_time;
	pthread_t		dead;
	pthread_mutex_t	mutex_util;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}					t_data;

//utils OK
int				ft_atoi(const char *str);
unsigned long	get_time(void);
unsigned long	get_passed_time(unsigned long begin);
void			smart_sleep(int	time_pass);
void			destroy(t_data *data);

//print OK
void			print_error(char *str);
int				print_action(t_data *data, int index, char *str);

//init OK
int				get_data(t_data *data, char **av);
void			mutex_init(t_data *data);
void			philo_init(t_data *data);

//check KO
int				is_death(t_data *data);

#endif