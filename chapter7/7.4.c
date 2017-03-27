#include<stdarg.h>

void minscanf(char *fmt, ...){
  va_list ap;
  char *p, *sval;
  int *ival;
 

  va_start(ap, fmt);
  for(p= fmt;*p;p++){

    if(*p != '%'){
      putchar(*p);
      continue;
    }
    switch(*++p){

    case 'd':
      ival = va_arg(ap, int *);
      scanf("%d",ival);
      break;
    }
  }
  va_end(ap);
}

int main(){
  int k;
  printf("Example of scanf\n");
  
  minscanf("%d",&k);
  printf("%d",k);
}
