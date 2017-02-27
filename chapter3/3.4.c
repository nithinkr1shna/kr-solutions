#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

void itoa(int num, char string[]);
void reverse(char string[]);

int main(){

  int n=-2147483648;
  char string[MAX];
  printf("the number is %d\n", n);
  itoa(n, string);
  
  
}

void itoa(int num, char string[]){
 
  int sign,i=0;
  sign= num;
  
  do{
    string[i++]= abs(num%10)+'0';
  }while((num/=10)!=0);

  if(sign < 0){
    string[i++]= '-';
  }
  
  string[i] ='\0';
  reverse(string);

}


void reverse(char string[]){
    int i;
    printf("the string is \n");
    for(i=strlen(string);i>=0;i--){
      printf("%c",string[i]);
    }
    printf("\n");
}

	 
