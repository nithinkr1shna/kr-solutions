


#include<stdio.h>
#include<string.h>
#define MAXLENGTH 1000

int mgetline(char string[], int lim);
int strindex(char s[], char t[]);

int main(){

  int length, found =0,i;
  char string[MAXLENGTH], pattern[MAXLENGTH];
  printf("Enter the pattern to search\n");
  mgetline(pattern, MAXLENGTH);
  printf("Enter the string to check\n");
  while (mgetline(string, MAXLENGTH) >0){
    if((i=strindex(string, pattern)) >= 0){
      printf("%s\n",string);
      printf("the position of occurance is\t%d\n",i-1);
    }
    return found;
    
  }
  
}

int mgetline(char string[], int limit){

  int i=0,c;
  while(--limit > 0 &&((c=getchar())!=EOF) && c!='\n')
    string[i++]=c;
  if(c=='\n')
    string[i++]==c;
  string[i]='\0';
  return i;
    
}

int strindex(char s[], char t[]){
  
  int i, j, k;
  int line_len = strlen(s)-1;
  int pattern_len = strlen(t)-1;
  
  for (i = line_len; i>=0; i--) {
    for (j=i, k=pattern_len; ((k>=0) && (s[j]==t[k]));j--,k--){
      
      if (k==0){
	
        return i;
      }
    }
  }
  
return -1;
 
}
