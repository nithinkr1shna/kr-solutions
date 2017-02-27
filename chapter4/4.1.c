#include<stdio.h>
#include<string.h>
#define MAXLENGTH 1000

int mgetline(char string[], int lim);
int strindex(char s[], char t[]);

int main(){

  int length, found =0;
  char string[MAXLENGTH], pattern[MAXLENGTH];
  printf("Enter the pattern to search");
  mgetline(pattern, MAXLENGTH);
  while (mgetline(string, MAXLENGTH) >0){
    if(strindex(string, pattern) >= 0){
      printf("%s",string);
      found++;
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
  int line_len = strlen(s);
  int pattern_len = strlen(t);
  
  for (i = line_len; i>=0; i--) {
    printf("%d\t",i);
    for (j=i, k=pattern_len; ((k>=0) && (s[j]==t[k]));j--,k--){
      printf("insidej %d\t",j);
      printf("insidek %d\t",k);
      
      if (k==0){
	
        return i;
      }
    }
  }
  
return -1;
 
}



