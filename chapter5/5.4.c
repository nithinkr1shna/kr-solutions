#include<stdio.h>
#include<string.h>
#define MAXLINE 100

int strend(char *, char *);
int mgetline(char s[], int lim);

int main(void){

  
    int len;
    char s[MAXLINE],t[MAXLINE];

    putchar('s');
    putchar(':');
    mgetline(s,MAXLINE);
    
    putchar('t');
    putchar(':');
    mgetline(t,MAXLINE);
    printf("%s",s);
    
    if (strend(s,t) ==1)
      printf("t is in tail");
    else
      printf("t not in tail");
    
} 

int strend(char *sp, char *tp){
  int sl, tl=0,counter=0, tl_counter=0, sp_len=0;
  char *tempp;
  tempp= tp;
  
  while(*tempp++ != '\0')
    tl++;
  tl= tl-1;
  tl_counter=tl;
 
  
  while(*sp++ != '\0')
    sp_len++;
  *sp--;
  sp_len--;
  while(tl_counter >= 0){
    *sp--;
    tl_counter--;
  }
  
  
  while((*sp++ == *tp++) && *tp != '\0')
    counter++;
  if(tl==counter )
     return 1;
  else
    return 0;
  
  
}

int mgetline(char s[],int lim)
{
    int c,i;
    
    for(i=0;i<lim-1 && (c=getchar()) !=EOF && c!='\n';++i)
        s[i] = c;
    
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    
    s[i] = '\0';

    return i;

}
