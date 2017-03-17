//program to display lines lexicographically and in order of numbers and folding of CAPS and LOCKS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINES 5000 /* max #lines to be sorted */
#define MAXLEN 5000
#define MAXSTORE 10000

char *lineptr[MAXLINES];/* pointers to text lines */
int fold =0;

int strcicmp(char const *a, char const *b);
int readlines(char *lineptr[], int nlines,char *ls);
void reverse(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void mqsort(void *lineptr[], int left, int right,int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int mgetline(char *, int lim);
/* sort input lines */
int main(int argc, char *argv[]){
  

  int nlines; /* number of input lines read */
  int numeric = 0; /* 1 if numeric sort */
  int recursive =0;
  char linestore[MAXSTORE];
  printf("\n\nProgram SORT-LEXICO & NUMERICAL order\nCommand-line arguments Usage:\n -r for reverse over lexographical order \n -nr or -rn for reverse over n \n -n for numerical order\n default: lexographical order\n\n\nEnter some lines\n\n");

  if ((argc >1 && strcmp(argv[1], "-f"))==0)
    fold =1;
  if ( (argc > 1 && strcmp(argv[1], "-nr")==0) ||(argc >1 && strcmp(argv[1],"-rn") ==0 ) ){
    numeric=1;
    recursive=1;
  }
  if (argc > 1 && strcmp(argv[1], "-n") == 0  ){  
        numeric =1;
  }
  if(argc>1 && strcmp(argv[1], "-r")==0){
      
	recursive =1;
  }
  
					     
  if ((nlines = readlines(lineptr, MAXLINES,linestore)) >= 0) {
    
      mqsort((void**) lineptr, 0, nlines-1,(int (*)(void*,void*))(numeric ? numcmp : strncasecmp));
      if(recursive==1){
        reverse(lineptr,nlines);
        //writelines(lineptr, nlines);
      }else{
        writelines(lineptr, nlines);
      }
    
    return 0;
   } else {
    printf("input too big to sort\n");
     return 1;
   }
}



int strcicmp(char const *a, char const *b)
{
    for (;; a++, b++) {
        int d = tolower(*a) - tolower(*b);
        if (d != 0 || !*a)
            return d;
    }
}

// helper function which reverses the sorted output of qsort

void reverse(char *lineptr[], int nlines){
  
  int linenum = nlines;
  while(nlines-- > 0)
    *lineptr++;
  
  *lineptr--;
  
  while(linenum-- >0)
    printf("%s\n",*lineptr--);
}

//helper function for writing the lines to output

void writelines(char *lineptr[], int nlines){

  while(nlines-- > 0)
    printf("%s\n", *lineptr++);
  
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

// helper functions used in mqsort

int numcmp(const char *s1, const char *s2){
  
  
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

//helper functions for reading from input

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
	  { line[len] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len+1; /* point p to next empty position */
	    
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
