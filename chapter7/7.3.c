#include<stdarg.h>
void minprintf(char *fmt, ...){
  va_list ap;
  char *p, *sval;
  int ival;
  double dval;

  va_start(ap, fmt);
  for(p= fmt;*p;p++){

    if(*p != '%'){
      putchar(*p);
      continue;
    }
    switch(*++p){

    case 'd':
      ival = va_arg(ap, int);
      printf("%d",ival);
      break;
    case 'f':
      dval = va_arg(ap, double);
      printf("%f",dval);
      break;
    case 's':
      for(sval = va_arg(ap, char); *sval;sval++)
	putchar(*sval);
      break;
    case 'x':
      printf("%x",va_arg(ap,int));
      break;
    case 'X':
      printf("%X",va_arg(ap,int));
      break;
    case 'o':
      printf("%o",va_arg(ap,int));
      break;
    case 'c':
      printf("%c",va_arg(ap,int));
      break;
    case 'e':
      printf("%e",va_arg(ap,double));
      break;
    case 'E':
      printf("%e",va_arg(ap,double));
      break;
    case 'g':
      printf("%g",va_arg(ap,double));
      break;
    case 'G':
      printf("%G",va_arg(ap,double));
      break;
    default:
      putchar(*p);
      break;
    }
  }
  va_end(ap);
}

int main(){
  minprintf("hai\n");
  minprintf("%x\n",678);
  minprintf("%f\n",1.234);
}
