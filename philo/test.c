#include "philo.h"
#include "table.h"
#include "utils.h"
#include "philo_visualizer.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	size_t	len = 7;
	void	*lock_printf;
	t_table	*table;
	t_philo	*philos[len];

	philovisualizer_init(len);
	lock_printf = mutex_new();
	for (size_t i = 0; i < len; i++)
		philos[i] = philo__new(&(t_philo_args){
			.lock_printf = lock_printf,
			.time_to_die = 5000,
			.time_to_eat = (long []){1000, 2000, 1000, 2000, 1000, 100, 300}[i],
			.time_to_sleep = (long []){1500, 2500, 3000, 1000, 3500, 2500, 4000}[i],
			.must_eat = 0});
	table = table__new(&(t_table_args){len, philos});
	table__start(table);
	// usleep(10000000);
	// table__stop(table);
	table__wait(table);
	table__del(&table);
	for (size_t i = 0; i < len; i++)
		philo__del(&philos[i]);
	mutex_del(lock_printf);
}
