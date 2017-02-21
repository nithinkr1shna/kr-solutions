#include<stdio.h>

char to_upper(char string);

    int main(){
      char c;
      printf("Enter the string\n");
      while((c=getchar())!=EOF){
        printf("%c",to_upper(c));
    }
}

char to_upper(char c){
  return (c>='a' && c<='z') ?  c-32 : c;
}
