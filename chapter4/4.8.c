#include<stdio.h>
#include<string.h>
#define MAXLEN 50
#define MAXBUF 50

int mgetline(char s[], int lim);
void ungetch(int c);
int getch(void);
void ungets(char s[]);

char  buf[MAXLEN];
int bufp;
int main(){
  char string[MAXLEN];
  int c,k=0;
  mgetline(string, MAXLEN);
  ungets(string);
  
  
  while((c=getch())!=EOF){
    putchar(c);
    printf("\n");
  }

 
  for(k=0;k<MAXLEN;k++){
    buf[k]=0;
  }
}


int mgetline(char s[], int lim){
  
  int i, c;
  for(i=0;i<lim-1 && (c=getchar())!=EOF && c != '\n';i++){
      s[i]=c;
   }
   if(c=='\n')
     s[i++]=c;
      
   s[i]='\0';
  

  return i;

}



void ungetch(int c)
{
    if(bufp >= MAXBUF)
        printf("ungetch: too many characters\n");
    else{
        buf[bufp++]=c;

    }
}


int getch(void)
{
    return (bufp == 0)?buf[--bufp]:getchar();
}

void ungets(char s[])
{
  int i,k;
    
  i = 0;
  printf("ungets %c", s[i]);
  ungetch(s[i]);
}

