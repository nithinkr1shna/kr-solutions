#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<math.h>
#include<string.h>

#define MAXOP 100 
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define MINUS '-'
#define PLUS '+'
#define MOD '%'
#define DIVISION '/'
#define MULT '*'
#define PERIOD '.'
#define SHOWTOP '?'
#define DUP '#'
#define SWAP '~'
#define CLEAR '!'
#define IDENTIFIER 1

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void showTop(void);
void duplicate(void);
void swap(void);
void clear();
void mathFunctions(char s[]);

int sp =0;
  
int main(){
  
  int type;
  double op2;
  char s[MAXOP];
  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case IDENTIFIER:
	mathFunctions(s);
	break;
      case PLUS:
        push(pop() + pop());
        break;
      case MULT:
        push(pop() * pop());
        break;
      case MINUS:
        op2 = pop();
        push(pop() - op2);
        break;
      case MOD:
        op2 =pop();
	if(op2 != 0.0){
	 push(fmod(pop(),op2));
	 break;
	}
	else{
         printf("zero divisor error");
	 break;
	}
      case DIVISION:
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case SHOWTOP:
	showTop();
	break;
      case DUP:
	duplicate();
	break;
      case SWAP:
	swap();
	break;
      case CLEAR:
        clear();
        break;
      case '\n':
        printf("\t%.8g\n", pop());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
   }
 }
return 0;
}

double val[MAXVAL];
void push(double f){
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void){
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int getop(char s[]){

  int i, c;
  while ((s[0] = c = getch()) == ' ' || c == '\t') // skips white space
    ;
     
  s[1] = '\0';
  i = 0;
  
  if(isalpha(c)){
    while(isalpha(s[i++]=c)){
      c=getch();
    }
    s[i-1]='\0';
    if(c!=EOF){
      ungetch(c);
    }
    return IDENTIFIER;
  }
  if (!isdigit(c) && c != PERIOD  && c!= MINUS){ //returns operator +
    return c;
  }
  
  if(c==MINUS)
    if(isdigit(c=getch()) || c == PERIOD){
            s[++i]=c;
	   
    }
        else
        {
            if(c!=EOF)
                ungetch(c);
            return MINUS;
        }
  
  if (isdigit(c)) 
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == PERIOD) 
    while (isdigit(s[++i] = c = getch()))
     ;
  s[i] = '\0';
  if (c != EOF)
   ungetch(c);
 return NUMBER;
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

void showTop(){
  if(sp >0)
    printf("The top of stack is %g\n", val[sp-1]);
  else
    printf("The stack is empty\n");
}

void duplicate(){
  
  if(sp>0){
    double temp;
    temp = pop();
    push(temp);
    push(temp);
  }
  else{
    printf("stack is empty\n");
  }
}

void swap(){
    double temp1, temp2;
    temp1 =pop();
    temp2= pop();
    push(temp2);
    push(temp1);
  
}

void clear(){
  sp=0;
}

void mathFunctions(char s[]){
  int match =0;
  double op2;
  if(match == strcmp(s, "sin"))
    push(sin(pop()));
  else if(match == strcmp(s, "cos"))
    push (cos(pop()));
  else if(match == strcmp(s, "exp"))
    push(exp(pop()));
  else if(match == strcmp(s, "pow")){
    op2= pop();
    push(pow(pop(),op2));
  }else
    printf("%s is not supported\n", s);
    
}
