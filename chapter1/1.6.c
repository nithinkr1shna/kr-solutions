#include<stdio.h>

int main (int argc, char *argv[])
{
    int c;
    while((c=getchar())!=EOF){
      putchar(c);
      printf("%d",c!=EOF);
    }
    printf("%d",c!=EOF);
}
