/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:20:53 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/21 18:35:11 by cschiavo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_info
{
	size_t	num_philo;
	size_t	dead_time;
	size_t	time_eat;
	

}t_info;
typedef struct  s_philo
{
	size_t last_eat;
	size_t num_of_meal;
	pthread_t	*phil;
	pthread_mutex_t rfork;
	pthread_mutex_t lfork;
	
}t_philo;
#endif