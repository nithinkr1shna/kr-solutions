#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define BUFSIZE 200
#define LIMIT 20
#define MAXSIZE 1000

void fold(char );
void mputchar(char );
void *reset_p(char *p);
int  convert_to_hex(char );
void getch();
int ungetch(int );
void question(void);
char *p;

int main(){

  int c,i=0,index,j;
  int space_flag=0;
  int counter =0;
  char holder[MAXSIZE];
  question();
  while((c=getchar()) !=EOF){
    // mputchar(c);
    fold(c);
    }
}


void mputchar(char c){

     if(isgraph(c)){
         putchar(c);
       }else{
         printf("%X",c);
       }
     if(c=='\n'){
        printf("\n");
	question();
     }
}

void  fold(char c){

  char buffer[BUFSIZE];
  int i=0;
  int j=0;
  static int counter=0;
  if(!isspace(c) && (buffer[i++]=c) < BUFSIZE){
    counter++;
  }
  if(isspace(c))
    mputchar(c);
  if(counter <=LIMIT){
    for(j=0;j<i;j++){
      mputchar(buffer[j]);
    }
  }
  if(counter >= LIMIT){
    counter =0;
    printf("\n");
  }
}
void question(void){

  printf("\nEnter a sentence\n");
}
