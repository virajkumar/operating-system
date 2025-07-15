/* osapi.h */
#include <stdio.h>
#include "os.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define getposixfd(x) fds[(x)]

private bool isopen(fd);
private void setupfds(void);