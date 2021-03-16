
# include <sys/time.h>
# include "errors.h"

long				ft_get_time()
{
	struct timeval	mark_t;

	if (gettimeofday(&mark_t, NULL))
		return ERR_GETTIME;
	return (mark_t.tv_sec * 1000000 + mark_t.tv_usec);
}
