#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define MAXLINES 500
#define REMV 2 // string - REMV removes the '\n' and '\0'
#define MAXLEN 1000
#define MAXSTORE 10000

char *lineptr[MAXLINES];
void writelines(char *lineptr[], int nlines,int n,int argc);
void tail(char line[], int n);
int readlines(char *lineptr[], int n, char []);
int mgetline(char *, int);

int main(int argc, char** argv){

  int nlines,tail_len; /* number of input lines read */
  char linestore[MAXSTORE];
  printf("\nThe default tail length is 5 unless a length is given as cmd line argument \nEnter a sentence\n");
  if ((nlines = readlines(lineptr, MAXLINES,linestore)) >= 0) {
    writelines(lineptr, nlines,atoi(argv[1]),argc);
    
     return 0;
   } else {
      printf("no lines\n");
       return 1;
   }
  
  
  
}
void writelines(char *lineptr[], int nlines,int n, int argc){
  printf("passed argument is %d\n",n);
  int to_strip=0;
  //printf("%d",argc);
  int len = strlen(*lineptr);
  if (len >= n)
     to_strip= len-(n+1);
    
  
  
  
     
  printf("the length od string %d\n",len);
  printf("\nThe tail is: ");
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
