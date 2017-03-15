#include<stdio.h>
#include <string.h>
#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 1000
#define MAXSTORE 10000

char *lineptr[MAXLINES]; /* pointers to text lines */
int readlines(char *lineptr[], int nlines, char []);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);
/* sort input lines */

int main(){

  int nlines; /* number of input lines read */
  char linestore[MAXSTORE];
  if ((nlines = readlines(lineptr, MAXLINES,linestore)) >= 0) {
    qsort(lineptr, 0, nlines-1); 
    writelines(lineptr, nlines);
    return 0;
  } else {
    
    printf("error: input too big to sort\n");
    return 1;
  }
}


#define MAXLEN 1000 /* max length of any input line */
int mgetline(char *, int);
char *alloc(int);

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
        {   line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len; /* point p to next empty position */
        }
    return nlines;
}

/* readlines: read input lines */
int readlines2(char *lineptr[], int maxlines){

  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = mgetline(line, MAXLEN)) > 0)
    if (nlines >= maxlines  ) 
      return -1;
    else {
      line[len-1] = '\0'; /* delete newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
  }
return nlines;
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




/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
  
  while (nlines-- > 0)
  printf("%s\n", *lineptr++);
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right){

  int i, last;
  void swap(char *v[], int i, int j);
  if (left >= right) /* do nothing if array contains */
   return; /* fewer than two elements */
  swap(v, left, (left + right)/2);
  last = left;
  for (i = left+1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j){

  char *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
