#include<stdio.h>

int is_upper(char );

int main(){
  int c;
  while((c=getchar()) != EOF){
    if(c=='\n')
      continue;
    if(is_upper(c))
      printf("true\n");
    else
     printf("false\n");

  }
  return 0;
}

int is_upper(char c){

  if(c >= 'A' && c <= 'Z')
    return 1;
  else
    return 0;
}
