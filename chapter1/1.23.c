#include<stdio.h>
#define MAX 1000
#define TRUE 1
#define FALSE 0

int iscomment(char string[]);
void without_comments(int iscmt, char string[], int i);

int main(){
  FILE *file;
  int i=0;
  char c, file_content[MAX];
  file =fopen("testfile1.c","r");
  if(file){
    while((c=getc(file))!=EOF){
      file_content[i]=c;
      i++;
    }
  }
  fclose(file);
  iscomment(file_content); 
}


int iscomment(char string[]){
  int scmt=0,mcmt=0,i=0;
  
  while(string[i]!='\0'){
    
    if(scmt==TRUE && string[i]=='\n'){
      scmt=FALSE; 
    }
    else if(mcmt==TRUE && string[i]=='*' && string[i+1]=='/'){
      mcmt=FALSE;
      i++; 
    }
    else if(scmt==TRUE || mcmt==TRUE){
      i++;
      continue;
    }
    else if((string[i]=='/') && (string[i+1])=='/'){
        scmt=TRUE;
        i++;
    }
    else if((string[i]=='/') && ((string[i+1])=='*')){
        mcmt=TRUE;
    }
    else{
      putchar(string[i]);
     
    }
    i++;
    
  }
}



