#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAXLINES 500
#define REMV 2 // string - REMV removes the '\n' and '\0'
#define MAXLEN 1000
#define MAXSTORE 10000

char *lineptr[MAXLINES];
void writelines(char *lineptr[], int nlines,int n);
void tail(char line[], int n);
int readlines(char *lineptr[], int n, char []);
int mgetline(char *, int);

int main(int argc, char** argv){

  int nlines,tail_len; /* number of input lines read */
  char linestore[MAXSTORE];
  //if(argc>0)
  //  tail_len = atoi(argv[1]);
  // else
  //tail_len =5;
  
  if ((nlines = readlines(lineptr, MAXLINES,linestore)) >= 0) {
    printf("%d",nlines);
    writelines(lineptr, nlines,atoi(argv[1]));
    
     return 0;
   } else {
      printf("error: input too big to sort\n");
       return 1;
   }
  
  
  
}
void writelines(char *lineptr[], int nlines,int n){
  printf("passed argument is %d\n",n);
  int len = strlen(*lineptr);
  int to_strip= len-(n+1);
  
  
     
  printf("the length od string %d\n",len);
  while(nlines -- > 0)
    printf("%s\n", *lineptr+to_strip);
}

int mgetline(char *sp, int lim){
  int c,counter =0;
  for(;(c=getchar())!=EOF && c != '\n'; *sp++){
    *sp=c;
    counter++;
  }
  if(c=='\n'){
    *sp =c;
    *sp++;
  }
  *sp='\0';
  
 
  return counter;
}

void tail(char line[], int n){

  int len=strlen(line);
  printf("%d",len);
  
}


int readlines(char *lineptr[], int maxlines, char *ls)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    p = ls + strlen(ls); 
    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (strlen(ls) + len) > MAXSTORE)
            return -1;
        else
        {   line[len+1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len; /* point p to next empty position */
        }
    return nlines;
}
