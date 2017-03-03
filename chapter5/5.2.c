#include<stdio.h>
#include <ctype.h>

#define SIZE 50
#define BUFSIZE 50

int main(){

  int n,k;
  float array[SIZE];
  int getfloat(float *);
  for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    printf("%g",array[n]);
  printf("\n");
}


int getch(void);
void ungetch(int);

int getfloat(float *pn){
  
  int  c,sign;
  float power;
  while (isspace(c = getch())) 
    ;
  if(isalpha(c)){
    ungetch(c);
    while(isalpha(c=getch()))
      ;
  }
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c); 
    
    } 
  sign = (c== '-') ? -1 : 1;
  if (c == '+' || c == '-'){
    c = getch();
  }
  for (*pn = 0; isdigit(c);){
     *pn = 10 * *pn + (c - '0');
     c=getch();
  }
  if( c == '.')
        c = getch();

    for(power=1.0;isdigit(c);c=getch())
    {
        *pn = 10.0 * *pn + (c - '0');   /* fractional part */
        power *= 10.0;
    }

    *pn  *= sign / power;
    
  if (c != EOF)
    ungetch(c);
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

