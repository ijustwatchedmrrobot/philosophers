/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sozdamar <sozdamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:35:03 by sozdamar          #+#    #+#             */
/*   Updated: 2024/07/18 12:30:03 by sozdamar         ###   ########.fr       */
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
	
}