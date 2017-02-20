#include<stdio.h>
#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'

int main(){
  int c;
  while((c=getchar()) !=EOF ){
    if( c== SPACE || c== TAB || c== NEWLINE){
      printf("\n");
    }
    else{
      putchar(c);
    }
  }
}
