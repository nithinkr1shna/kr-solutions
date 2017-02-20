#include<stdio.h>
#define MAXLENGTH 1000

int mgetline(char string[], int lim);
void reverse(char string[],int length);
int main(){
  
  int len;
  
  char string[MAXLENGTH],longest[MAXLENGTH];
  while ((len= mgetline(string, MAXLENGTH)) > 0){
    reverse(string, len);  
     
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


void reverse(char string[], int length){
  int i;
  printf("\n\nThe string in reverse\n");
  for(i=length;i<=length;i--){
    printf("%c",string[i]);
    if(i<0)
      break;
  }
  printf("\n");
}
