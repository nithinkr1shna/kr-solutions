#include<stdio.h>
#include<sys/file.h>
#include<unistd.h>
#include<stdlib.h>

#define PERMS 0666

#define EOF (-1)
#define OPEN_MAX 20

struct flag_field{
    unsigned f_read : 1;
    unsigned f_write : 1;
    unsigned f_unbuf : 1;
    unsigned f_buf : 1;
    unsigned f_eof : 1;
    unsigned f_err : 1;
} flag;


typedef struct _iobuf{
    int cnt; 
    char *ptr; 
    char *base;
    struct flag_field flag; 
    int fd;
} _FILE;

extern _FILE _iob[OPEN_MAX];

_FILE _iob[OPEN_MAX] = {
    {0, (char *) 0, (char *) 0, {1,0,0,0,0}, 0},
    {0, (char *) 0, (char *) 0, {0,1,0,0,0}, 1},
    {0, (char *) 0, (char *) 0, {0,1,1,0,0}, 2}
};



_FILE *_fopen(char *name, char *mode){
    int fd;
    _FILE *fp;    
    
    if(*mode != 'r' && *mode != 'w' && *mode != 'a')
        return NULL;
    for(fp = _iob; fp< _iob + OPEN_MAX; fp++)
        if(fp->flag.f_read == 0 && fp->flag.f_write == 0)
            break; 
    if(fp>=_iob + OPEN_MAX)
        return NULL; 
    if(*mode == 'w') 
        fd = creat(name, PERMS);
    else if(*mode == 'a')
    {
        if((fd = open(name, O_WRONLY, 0)) == -1)
            fd = creat(name, PERMS);
        lseek(fd, 0L, 2);
    }
    else
        fd = open(name, O_RDONLY, 0);
    if(fd == -1) 
        return 0;
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = 0;
    fp->flag.f_unbuf = 0;
    fp->flag.f_buf = 1;
    fp->flag.f_eof = 0;
    fp->flag.f_err = 0;
    if(*mode == 'r')
    {
        fp->flag.f_read = 1;
        fp->flag.f_write = 0;
    }
    else 
    {
        fp->flag.f_read = 0;
        fp->flag.f_write = 1;
    }
    return fp;
}


int _fillbuf(_FILE *fp){

    int bufsize;
    
    if(fp->flag.f_read == 0 || fp->flag.f_eof == 1 || 
        fp->flag.f_err == 1)
        return EOF;
    bufsize = (fp->flag.f_unbuf == 1) ? 1 : BUFSIZ;
    if (fp->base == NULL) 
        if((fp->base = (char *) malloc(bufsize)) == NULL)
            return EOF; 
    fp->ptr = fp->base;
    fp->cnt = read(fp->fd, fp->ptr, bufsize);
    if(--fp->cnt < 0){
      
        if(fp->cnt == -1)
            fp->flag.f_eof = 1;
        else
            fp->flag.f_err = 1;
        fp->cnt = 0;
        return EOF;
    }
    return (unsigned char) *fp->ptr++;
}
