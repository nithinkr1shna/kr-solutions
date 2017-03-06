#include<stdio.h>
#include<string.h>
#define MAXLEN 100

int mgetline( char *, int lim);
void itoa(int n, char *);
int atoi(char *);
void reverse(char *);
//void strindex();
//void getop();

int main(){
  int len,n;
  char s[MAXLEN],ato_i[MAXLEN],rvrs[MAXLEN],ito_a[MAXLEN];
  len = mgetline(s,MAXLEN);
  printf("%s",s);
  printf("%d",len);
  printf("\n");

  printf("---reverse---\n");
  reverse(s);
  printf("%s\n",s);
  printf("\n");

  printf("---itoa---\n");
  printf("Enter the integer\n");
  scanf("%d\n",&n);
  itoa(n,ito_a);
  printf("%s\n",ito_a);
  
  printf("---\t--atoi--\t----\n");
  printf("enter the array of digit\n");
  mgetline(ato_i,MAXLEN);
  printf("%d\n",atoi(ato_i));
  

}

int mgetline(char *sp, int lim){
  int c,counter =0;
  for(;(c=getchar())!=EOF && c != '\n'; *sp++){
    *sp=c;
    counter++;
  }
  if(c=='\n'){
    *sp =c;
    *sp++;
  }
  *sp='\0';
 

  return counter;
}
#include<ctype.h>
#define MINUS -1

int  atoi(char *s){
  
  int n,sign;

    for(;isspace(*s);s++)   /* skip white space */
        ;
    sign = ( *s =='-')? -1:1;

    if(*s=='+' || *s=='-')
        s++;
    for(n=0;isdigit(*s);s++)
        n = 10 *n + *s - '0';
    
    return sign * n;
    
    
  
  
}

void reverse(char *s){
 int c;
 char *t;

    for(t=s+(strlen(s)-1);s<t;s++,t--)
    {
        c=*s;
        *s=*t;
        *t=c;
    }
}

void itoa(int n, char *s){

  int sign;
    char *t=s;
    
    if((sign = n) < 0)
        n = -n;

    do
    {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);

    if(sign < 0)
        *s++ = '-';
    *s='\0';

  
}
