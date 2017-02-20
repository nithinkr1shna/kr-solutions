#include<stdio.h>
#include<string.h>

#define MAX 100

void squeeze(char s1[], char s2[]);

int main(){

  char s1[MAX],s2[MAX];
  printf("Enter the strings\n");
  scanf("%s",s1);
  scanf("%s",s2);
  //printf("%s %s",s1,s2);
  squeeze(s1,s2);
  
}

void squeeze(char s1[], char s2[]){
  int size1,size2,i,j;
  size1=strlen(s1);
  size2 =strlen(s2);
  for (j=0; j<size2; j++){
        for (i=0; i<size1; i++){
             if (s2[j]==s1[i])
                 s1[i]=' ';
        }
    }
  printf("%s\n", s1);
}


