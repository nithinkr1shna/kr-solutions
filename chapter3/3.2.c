#include<stdio.h>
#define MAX 500
void escape(char s[], char t[]);
int mgetline(char s[], int lim);

int main(){
  
  int len;
  char c;
  char string[MAX],t[MAX];
  mgetline(string,len);
  escape(t, string);
  printf("%s",t);
 
}

void escape(char s[], char t[]){
  int i=0,j=0;
  while(t[i]!='\0'){
    switch(t[i]){
      case '\t':
        s[j]=='\\';
	j++;
	s[j]=='t';
	break;
	
      case '\n':
	s[j]=='\\';
	j++;
	s[j]=='n';
	break;

      default:
	s[j]=t[i];
	break;
    }
    i++;
    j++;
  }
  s[j]='\0';
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
