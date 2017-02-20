#include<stdio.h>
#include<string.h>

#define MAX 100

int  any(char s1[], char s2[]);

int main(){

  char s1[MAX],s2[MAX];
  int value;
  printf("Enter the strings\n");
  scanf("%s",s1);
  scanf("%s",s2);
  value = any(s1,s2);
  printf("%d",value);
}

int any(char s1[], char s2[]){
  int size1,size2,i,j,pos=MAX;
  size1=strlen(s1); 
  size2 =strlen(s2); 
  for (j=0; j<size2; j++){
        for (i=0; i<size1; i++){
	  if (s2[j]==s1[i])
	       if(pos> i)
		 pos =i;
	  
	 
        }
    }
  
  if(pos == MAX){

    return -1;
  }
  else if(pos<MAX){
    
    return pos;
  }
}


