#include<stdio.h>
#include <ctype.h>

#define SIZE 50
#define BUFSIZE 50

int main(){

  int n, array[SIZE], getint(int *),k;
  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;

  for(k=0; k<n  && array[n]!='\0';k++){
    printf("%d",array[n]);
  }
  printf("\n");
}


int getch(void);
void ungetch(int);
/* getint: get next integer from input into *pn */
int getint(int *pn){
  
  int c, sign;
  while (isspace(c = getch())) /* skip white space */
    ;
  if(isalpha(c)){
    ungetch(c);
    while(isalpha(c=getch()))
      printf("%c",c);
  }
  /*if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); 
    
    } */
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  for (*pn = 0; isdigit(c);){
    *pn = 10 * *pn + (c - '0');
    c=getch();
  }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  if(c=='\n')
    return '\0';
  return c;
}

char buf[BUFSIZE];
int bufp=0;

int getch(void){
  
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
