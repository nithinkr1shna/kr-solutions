#include<stdio.h>
#include<string.h>
#define MAXLINE 100

void mystrcat(char *,char *);
int mgetline(char s[], int lim);

int main(void)
{
    int len;
    char s[MAXLINE],t[MAXLINE];

    putchar('s');
    putchar(':');
    mgetline(s,MAXLINE);
    
    putchar('t');
    putchar(':');
    mgetline(t,MAXLINE);
    
    mystrcat(s,t);

    printf("the string is : %s",s);

    return 0;
}

void mystrcat(char *sp, char *tp){
   
  while(*sp++ !='\0'){
     
  }
  *sp--;
  
  while((*sp++ = *tp++) != '\0'){
    ;
  }
  
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
