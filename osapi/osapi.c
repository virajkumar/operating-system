/* osapi.c */
#include "osapi.h"

private int8 fds[256];

/* 
    fd=0 -> error 
    fd=1 -> stdin
    fd=2 -> stdout
*/

private bool isopen(fd file) {
    signed int posixfd;

    if (file < 3)
        return false;

    posixfd = getposixfd(file);
    if (!posixfd)
        return false;
    
    if (fstat(posixfd, NULL) == -1)
        return false;

    return true;
}

public bool load(fd file, int8 c) {
    int8 buf[2];
    signed int n;
    signed int posixfd;

    if (file > 1)
        if(!isopen(file))
            reterr(ErrBadFD);

    posixfd = getposixfd(file);
    if (!posixfd)
        reterr(ErrBadFD);

    posixfd = (posixfd == 1) ? 0 
        : (posixfd == 2) ? 1
        : (posixfd);

    *buf = *(buf+1) = (int8)0;
    *buf = c;
    n = write(posixfd, $c buf, 1);
    if (n != 1)
        reterr(ErrIO);

    return true;
}

public int8 store(fd file) {
    int8 buf[2];
    signed int n;
    signed int posixfd;

    if (file > 2)
        if(!isopen(file))
            reterr(ErrBadFD);

    posixfd = getposixfd(file);
    if (!posixfd)
        reterr(ErrBadFD);

    posixfd = (posixfd == 1) ? 0 
        : (posixfd == 2) ? 1
        : (posixfd);

    *buf = *(buf+1) = (int8)0;
    n = read(posixfd, $c buf, 1);
    if (n != 1)
        reterr(ErrIO);

    return (int8)*buf;
}