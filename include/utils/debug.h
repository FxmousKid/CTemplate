#ifndef DEBUG_H
# define DEBUG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
# include <stdint.h>
# include <stdbool.h>
# include <unistd.h>

# ifndef LOGFILE_PATH
#  define LOGFILE_PATH	"executable.log"
# endif

# define STRINGIFY(x) #x
# define TOSTRING(x) STRINGIFY(x)
# define DBG __FILE__ " @ " TOSTRING(__LINE__)
# define ERR_SYS(...) do {dprintf(get_logfd(), "[ERROR] "); dprintf(get_logfd(), __VA_ARGS__); _write_perr(DBG); } while (0);
# define ERR_MSG(...) do {dprintf(get_logfd(), "[ERROR] "); dprintf(get_logfd(), __VA_ARGS__); _write_err(DBG); } while (0);

int		get_logfd(void);
void		_write_perr(const char *location);
void		_write_err(const char *location);

#endif
