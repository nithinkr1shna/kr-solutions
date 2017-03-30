#include<stdio.h>
#include<sys/file.h>
#include<stdlib.h>
#include<unistd.h>

#define BUFSIZE 5000 

int main(int argc, char **argv){

  int fd,i=0,n;
  char buf[BUFSIZE];
  if(argc == 1){
    printf("Enter file names as command line arguments\n");
    exit(0);
  }else{
    for(;argc-- > 0;i++){

      fd =open(argv[i],O_RDONLY,0);
      n=read(fd,buf,BUFSIZE);
      if(write(1,buf,n) !=n)
	printf("Write Error\n");
      close(fd);
    }
  }

}
