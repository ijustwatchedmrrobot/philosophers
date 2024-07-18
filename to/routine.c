/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:35:03 by sozdamar          #+#    #+#             */
/*   Updated: 2024/07/18 16:33:49 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking(t_data *data, int index)
{
	if (print_action(data, index, "is thinking"))
		return (1);
	return (0);
}

int	sleeping(t_data *data, int index)
{
	if (print_action(data, index, "is sleeping"))
		return (1);
	smart_sleep(data->sleep_time);
	return (0);
}

int	eating(t_data *data, int index)
{
	if (!is_death(data))
	{
		pthread_mutex_lock(&data->forks[index]);
		print_action(data, index, "has taken a fork");
		pthread_mutex_lock(&data->forks[(index + 1) % data->num_of_philo]);
		print_action(data, index, "has taken a fork");
		print_action(data, index, "is eating");
		pthread_mutex_lock(&data->mutex_util);
		data->philo[index].last_eat = get_time();
		data->philo[index].meals++;
		pthread_mutex_unlock(&data->mutex_util);
		smart_sleep(data->eat_time);
		pthread_mutex_unlock(&data->forks[index]);
		pthread_mutex_unlock(&data->forks[(index + 1) % data->num_of_philo]);
		return (0);
	}
	return (1);
}

void	*routine(void *v_data)
{
	t_data	*data;
	int		index;

	data = (t_data *)v_data;
	pthread_mutex_lock(&data->mutex_util);
	index = data->thread_index;
	pthread_mutex_unlock(&data->mutex_util);
	while (1)
	{
		if (data->num_eat != data->philo[index].meals)
		{
			if (is_death(data) || eating(data, index))
				break;
			if (is_death(data) || sleeping(data, index))
				break;
			if (is_death(data) || thinking(data, index))
				break;
		}
		else
			break;
	}
	return (NULL);
}

void	*only_one_philo(void *v_data)
{
	t_data	*data;
	
	data = (t_data *)v_data;
	data->start_time = get_time();
	print_action(data, 0, "has taken fork");
	smart_sleep(data->die_time);
	printf("%-10lu %d died", get_passed_time(data->start_time), data->philo[0].philo_id);
	return (NULL);
}