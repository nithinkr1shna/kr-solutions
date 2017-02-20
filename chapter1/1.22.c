#include<stdio.h>
#define MAXLENGTH 1000
#define MAXCOLOUMN 60

int last_blankcharacter_pos(char string[], int length);
void display(int from, int to, char string[]);
int mgetline(char string[], int lim);
int main(){
  
  int len;
  
  char string[MAXLENGTH],longest[MAXLENGTH];
  while ((len= mgetline(string, MAXLENGTH)) > 0){
    last_blankcharacter_pos(string, len);  
     
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

int last_blankcharacter_pos(char string[], int length){
  int pos=0,k;
  int i=0,start=0;
  while(i<=length){
    i++;
    if(string[i]==9 || string[i]==32){
      pos= i;
      
      
    }
    if(i%MAXCOLOUMN==0){
       display(start,pos,string);
       start=pos;
       
       
    }
   
    
  }
}
void display(int from, int to, char string[]){
  int i;
  for(i=from;i<=to;i++){
    printf("%c",string[i]);
  }
  printf("\n");
}

