#include "utils/debug.h"

int	get_logfd(void)
{
	static int fd = 0;

	if (fd == 0)
		fd = open(LOGFILE_PATH, O_RDWR | O_CREAT | O_TRUNC, 0644);

	if (fd < 0) {
		printf("Could not create logfile\n");
		exit(2);
	}

	return fd;
}

/**
 * @brief prints on logfile a system error msg with location
 */
void	_write_perr(const char *location)
{
	dprintf(get_logfd(), ": %s [%s]\n", strerror(errno), location);
}

/**
 * @brief prints on logfile a custom error msg with location
 */
void	_write_err(const char *location)
{
	dprintf(get_logfd(), " [%s]\n", location);
}
