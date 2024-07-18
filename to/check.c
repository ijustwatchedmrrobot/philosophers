/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:34:49 by sozdamar          #+#    #+#             */
/*   Updated: 2024/07/18 11:59:54 by sozdamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_death(t_data *data)
{
	pthread_mutex_lock(&data->mutex_util);
	if (data->is_philo_dead == 1)
	{
		pthread_mutex_unlock(&data->mutex_util);
		return (1);
	}
	pthread_mutex_unlock(&data->mutex_util);
	return (0);
}