#include<stdio.h>
#define MAXLENGTH 1000
#define TABINC 4

int main(){
  int num_of_spaces=0, num_of_tabs=0,i;
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
