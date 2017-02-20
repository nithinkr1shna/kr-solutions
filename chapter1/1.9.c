#include<stdio.h>

int main(){
  int c;
  int lastcharacter = '-';
  while ((c=getchar())!=EOF){

    if (c==' '){
      if (lastcharacter!=' '){
          putchar(c);
      }
     }
    else{
      putchar(c);
    }

    lastcharacter=c;
  }
}
