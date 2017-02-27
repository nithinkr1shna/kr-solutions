#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
#define MINWIDTH 10

void itoa(int num, char string[], int width);
void reverse(char string[]);

int main(){

  int n;
  printf("enter the integer");
  scanf("%d",&n);
  char string[MAX];
  printf("the number is %d\n", n);
  itoa(n, string, MINWIDTH);
  
  
}

void itoa(int num, char string[], int width){
 
  int sign,i=0,len;
  if((sign= num)<0){
    num = -num;
  }
  
  do{
    string[i++]= num%10+'0';
  }while((num/=10)>0);

  if(sign < 0){
    string[i++]= '-';
  }
  
  printf("%s",string);
  
  len = strlen(string);
  if(len<MINWIDTH){
    while(len<=MINWIDTH){
      string[i++]=' ';
      len++;
    }
    
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

	 
