#include<stdio.h>

int  main(){
  int c;
  while((c=getchar())!=EOF){
    if(c == '\t' || c == '\n'|| c == ' '){
      printf("\n");
    }
    else{
      printf("*");
    }
    
}
}
