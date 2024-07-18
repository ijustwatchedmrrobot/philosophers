/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:35:00 by sozdamar          #+#    #+#             */
/*   Updated: 2024/07/18 11:54:06 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_error(char *str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

int	print_action(t_data *data, int index, char *str)
{
	pthread_mutex_lock(&data->mutex_util);
	if (data->num_eat == data->philo[index].meals || 
		data->is_philo_dead == 1)
	{
		pthread_mutex_unlock(&data->mutex_util);
		pthread_mutex_unlock(&data->forks[index]);
		pthread_mutex_unlock(&data->forks[(index + 1) % data->num_of_philo]);
		return (1);
	}
	printf("%-10lu %d %s", get_passed_time(data->start_time),
		data->philo[index].philo_id, str);
	pthread_mutex_unlock(&data->mutex_util);
	return (0);
}