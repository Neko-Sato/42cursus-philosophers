#include "philo.h"
#include "table.h"
#include "utils.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	size_t	len = 49;
	void	*lock_printf;
	t_table	*table;
	t_philo	*philos[len];

	lock_printf = mutex_new();
	for (size_t i = 0; i < len; i++)
		philos[i] = philo__new(&(t_philo_args){lock_printf, 1000, 100, 100, 0});
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
