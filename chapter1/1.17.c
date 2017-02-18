#include<stdio.h>
#define MAXLENGTH 1000
#define UPPERLENGTHLIMIT 79

int mgetline(char string[], int lim);
void string_length_80_above(char str[], int length);

int main(){
  
  int len, upper=UPPERLENGTHLIMIT;
  char string[MAXLENGTH],longest[MAXLENGTH];
  while ((len= mgetline(string, MAXLENGTH)) > 0){
    string_length_80_above(string,len); 
     
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

void string_length_80_above(char str[], int length){
  if (length > UPPERLENGTHLIMIT)
    printf("%2d\t\t%s",length, str);
  else
    printf("Entered string is less than 80 characters\n\n");
  
}
