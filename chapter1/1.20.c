#include<stdio.h>
#define MAXLENGTH 1000
#define TABINC 4

int main(){
  int i;
  char c;
  while((c=getchar())!=EOF){
    if (c=='\t'){
      for(i=0;i<=TABINC;i++)
	putchar(' ');
    }
    else {
      putchar(c);
    }
  }
}
