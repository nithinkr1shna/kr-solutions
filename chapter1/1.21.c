
 
#include<stdio.h>
#define MAXLENGTH 1000
#define TABLEN 5

void entab(char string[]);
int mgetline(char string[], int lim);
int main(){
  
  int len;
  
  char string[MAXLENGTH],longest[MAXLENGTH];
  while ((len= mgetline(string, MAXLENGTH)) > 0){
    entab(string); 
 
  }
 
}

int mgetline(char string[], int lim){
  int i, c;
  for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
    string[i]=c;
  if(c=='\n'){
    string[i]=c;
    ++i;
  }
  string[i]='\0';
  return i;
}

void entab(char string[])
{
    int i, space;
    int to, from, tabloc;
        printf("%s\n",string);

    space = 0;
    for (i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ')
	  ++space;
        else
	  space = 0;

        if (space >= TABLEN) {
            
            tabloc = (i - TABLEN) + 1;

            for (to = tabloc+1, from = i+1;
                 string[from] != '\0'; ++from, ++to)
            {
                
                string[to] = string[from];
            }

            string[tabloc] = '\t';
            string[to] = '\0';
            i = tabloc+1;
            space  = 0;
        }
    }
    printf("%s",string);
}


