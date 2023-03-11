#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	*test(void *data)
{
	int	a;
	int	i = 0;
	a = *(int *)data;
	while (i++ < 5)
		printf("%d\n", a);
	usleep(1);
	return (0);
}

int main(void)
{
	int	i = 0;
	int	a = 100;
	int	status;
	pthread_t th;
	while (i < 10)
	{
		pthread_create(&th, NULL, test, (void *)&a);
		pthread_join(th, (void **)&status);
		printf("status : %d\n", status);
		i++;
	}
	return (0);
}