#include<stdio.h>
#define MAXLEN 50

void itoa(int num);

int main(){


  int c;
  int num;
  printf("Input digits\n");
  scanf("%d",&num);
  itoa(num);
}

void itoa(int n){
  int sign;
  if(n < 0){
    n=-n;
    putchar('-');
  }
  if(n/10){
    itoa(n/10);
  }
  putchar(n%10+'0');
 
}
