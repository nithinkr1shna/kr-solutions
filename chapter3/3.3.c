#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int mgetline(char s[], int lim);
char expand(char s1, char s2);

int main(){
  char string[MAX];
  int i,len,start,end;
  len = mgetline(string, MAX);
  printf("%s",string);
  for(i=0;i<len;i++){
    if(((string[i] >='a' && string[i] <='z')||(string[i]>='A' && string[i] <='Z')) && (string[i+1]=='-') && ((string[i+2] >='a' && string[i+2] <='z') || (string[i+2]>='A' && string[i+2]<='Z'))){
      expand(string[i], string[i+2]);
      i=i+2;
      
    }
    else if((string[i]>='0' && string[i]<='9') && string[i+1]=='-'){
      expand(string[i],string[i+2]);
      i=i+2;
    }
    else{
      putchar(string[i]);
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

char expand(char s1, char s2){
  int i;
  int k =s1,l=s2;
  for(i=k;i<=l;i++){
    printf("%c",i);
  }
}
