/* os.h */

#define bool int8
#define true 1
#define false 0

typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;
typedef unsigned long long int int64;
typedef int8 fd;
typedef int8 error;

#define $1 (int8 *)
#define $2 (int16)
#define $4 (int32)
#define $8 (int64)
#define $c (char *)
#define $i (int)

#define ErrNoErr 0
#define ErrInit 1
#define ErrIO 4
#define ErrBadFD 8

#define public __attribute__((visibility("default")))
#define private static

#define reterr(x) do {\
    errnumber = (x);      \
    return 0;         \
} while(false);

error errnumber;

public bool initialized;

/* write 1 char */
public bool load(fd, int8);

/* read 1 char */
public int8 store(fd);

public void init(void);