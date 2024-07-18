/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:34:44 by sozdamar          #+#    #+#             */
/*   Updated: 2024/07/18 10:49:23 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0') * sign;
		if (res > 2147483647 || res < -2147483648)
			return (-1);
		i++;
	}
	return ((int)res);
}

unsigned long	get_time(void)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

unsigned long	get_passed_time(unsigned long begin)
{
	return (get_time() - begin);
}

void	smart_sleep(int	time_pass)
{
	unsigned long	time_now;

	time_now = get_time();
	while (get_time() <= time_now + time_pass)
		usleep(100);
}

void	destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->mutex_util);
}
