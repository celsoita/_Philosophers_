/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschiavo <cschiavo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 17:20:53 by cschiavo          #+#    #+#             */
/*   Updated: 2023/07/23 11:25:56 by cschiavo         ###   ########.fr       */
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
# include <stdbool.h>

typedef struct s_info
{
	size_t	num_philo;
	size_t	dead_time;
	size_t	time_eat;
	size_t	sleep_time;
	useconds_t	start_time;
	pthread_mutex_t print;
	pthread_mutex_t *forks;
}		t_info;

typedef struct  s_philo
{
	size_t		id;
	//num of times each philo eat
	size_t		eat_times;
	//last eat of philo
	useconds_t last_eat;
	//number of meal total
	size_t num_of_meal;
	pthread_t	philo;
	pthread_mutex_t *rfork;
	pthread_mutex_t *lfork;
	t_info		*info;
	
}		t_philo;

//ft_philo_utils
int		ft_atoi(const char *str);
int		ft_time_ms(void);
void	ft_mutex_printf(useconds_t time,t_philo *philo, char *str);
//ft_check_arg
int		ft_isdigit(char *str);
int		ft_check_arg(int argc, char **argv);
bool	ft_perror(char *str);
//ft_philo_init
void	ft_info(char **argv, t_info *info);
void ft_philo_init(t_philo philo, size_t id);

#endif