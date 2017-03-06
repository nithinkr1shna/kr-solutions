#include<stdio.h>
#define MAXLEN 100

void mystrncpy(char *, char *, int k);
void mystrncat(char *sp, char *tp, int k);
int mystrncmp(char *, char *, int k);
int mgetline(char s[], int lim);
int main(){

  char s[MAXLEN],t[MAXLEN],str[MAXLEN];
  int k,return_val;
  
  putchar('s');
  putchar(':');
  mgetline(s,MAXLEN);

  putchar('t');
  putchar(':');
  mgetline(t,MAXLEN);

  
  putchar('n');
  putchar(':');
  scanf("%d",&k);
  


  printf("Stringcat\n");
  printf("String : %s\t t: %s\t pos : %d\n",s,t,k);
  mystrncat(s,t,k);
  printf("result :%s\n",s);
  
  printf("\n\n");
  
  printf("Stringcpy\n");
  mystrncpy(str,t,k);
  printf("result :%s\n",str);

  printf("\n\n");

  printf("StringCmp\n");
  return_val =mystrncmp(s,t,k);
  if(return_val ==0){
    printf("the strings are equal\n");
  }
  else if(return_val > 0){
    printf("string s > t");
  }
  else
    printf("string s < t");
  
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

void mystrncat(char *sp, char *tp, int k){
  
  int counter=0;
  while((*sp++ !='\n'))
    ;
  *sp--;
  
  while((*sp++ = *tp++) !='\n' && counter++ < k-1 )
    ;
}

void mystrncpy(char *sp, char *tp, int k){
  int counter =0;
  while((*sp++= *tp++) !='\0' && counter++ < k-1)
    ;
  
}

int  mystrncmp(char *s, char *t, int k){
  int counter=0;
  for ( ; *s == *t && t++ < k-1; s++, t++)
   if (*s == '\0')
     return 0;
  return *s - *t;

}
