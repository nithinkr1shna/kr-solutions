#include<stdio.h>
#include<string.h>

#define MAX 100

void itob(int n, char string[], int base);
void reverse(char string[], int base);

int main(){
  
  int num,base;
  char str[MAX];
  printf("Enter the number\n");
  scanf("%d",&num);
  printf("Enter the base\n");
  scanf("%d",&base);
  itob(num,str,base);
  reverse(str, base);
}

void itob(int n, char string[], int base){

  int sign,i=0,j;
   if((sign=n) <0){
     n=-n;
   }
  
  do{
    j = n % base;
    
    string[i++]= (j<=9)? j+'0' : j+'a'-10;
  }while((n/=base)>0);
  
  

  if(sign < 0){
    string[i++]= '-';
  }
  
  string[i] ='\0';

  
}
void reverse(char string[], int base){
  
    int i;
    printf("the string w.r.t base %d is\n", base);
    for(i=strlen(string);i>=0;i--){
      printf("%c",string[i]);
    }
    printf("\n");
}
