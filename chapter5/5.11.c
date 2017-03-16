#include<stdio.h>
#define MAXLENGTH 1000

void entab(char string[]);
int mgetline(char string[], int lim);

int tablen;

int main(int argc, char *argv[]){
  int i,tabinc,choice,len;
  char c;
  printf("1.For detab\n2. For Entab\n");
  scanf("%d",&choice);

  if(choice ==1){
    
    if(argc > 0){
      for(i=0;i<argc;i++)
        tabinc=*argv[i];
    }else
    tabinc =4;
    while((c=getchar())!=EOF){
      if (c=='\t'){
        for(i=0;i<=tabinc;i++)
	  putchar(' ');
      }
      else {
        putchar(c);
      }
    }
  }



 else if(choice ==2){
    
  
    char string[MAXLENGTH],longest[MAXLENGTH];
    if(argc>0)
      for(i=0;i<argc;i++){
        tablen =*argv[i];
     }
    else
      tablen = 5;
    while ((len= mgetline(string, MAXLENGTH)) > 0){
      entab(string); 
 
    }
 
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

    space = 0;
    for (i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ')
	  ++space;
        else
	  space = 0;

        if (space >= tablen) {
            
            tabloc = (i - tablen) + 1;

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

