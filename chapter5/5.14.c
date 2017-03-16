#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 5000
#define MAXSTORE 10000
char *lineptr[MAXLINES];/* pointers to text lines */


int readlines(char *lineptr[], int nlines,char *ls);
void writelines(char *lineptr[], int nlines);
void mqsort(void *lineptr[], int left, int right,int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[]){
  

  int nlines; /* number of input lines read */
  int numeric = 0; /* 1 if numeric sort */
  char linestore[MAXSTORE];
  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES,linestore)) >= 0) {

    // I am not getting how this call to mqsort works. The function definition of
    // mqsort seems to accept the function as the 3rd argument but
    // this "(int (*)(void*,void*))(numeric  ? numcmp : strcmp) " section is really
    // confusing.
    
    mqsort((void**) lineptr, 0, nlines-1,(int (*)(void*,void*))(numeric  ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
   } else {
    printf("input too big to sort\n");
     return 1;
   }
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


void mqsort(void *v[], int left, int right,int (*comp)(void *, void *)){

  int i, last;
  void swap(void *v[], int, int);
  if (left >= right) /* do nothing if array contains */
    return; /* fewer than two elements */
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  mqsort(v, left, last-1, comp);
  mqsort(v, last+1, right, comp);
}

int numcmp(char *s1, char *s2){

  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j){
  
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
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
