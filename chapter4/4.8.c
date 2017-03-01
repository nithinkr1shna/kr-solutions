#include<stdio.h>
#include<string.h>
#define MAXLEN 50
#define MAXBUF 50

int mgetline(char s[], int lim);
void ungetch(int c);
int getch(void);
void ungets(char s[]);

char buf[MAXLEN];

int main(){
  char string[MAXLEN];
  int c,k;
  mgetline(string, MAXLEN);
  ungets(string);
  while((c=getch())!=EOF){
    putchar(c);
  }

  for(k=0;k<MAXLEN;k++){
    buf[k]=0;
  }
}

int mgetline(char s[], int lim){
  
  int i, c;
  for(i=0;i<lim-1 && (c=getchar())!=EOF&& c!='\n';++i){
    s[i]=c;
  }
  if(c=='\n')
    s[i++]=c;
  s[i]='\0';

  return i;

}

int bufp;

void ungetch(int c)
{
    if(bufp >= MAXBUF)
        printf("ungetch: too many characters\n");
    else{
        buf[bufp++]=c;
	printf("buff is %s",buf);
    }
}


int getch(void)
{
    return (bufp > 0)?buf[--bufp]:getchar();
}

void ungets(char s[])
{
  int i,k;
    
  i = 1;
  ungetch(s[--i]);
}

