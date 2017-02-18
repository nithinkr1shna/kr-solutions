#include<stdio.h>
#define MAXLENGTH 1000


int mgetline(char string[], int lim);
void remove_trailing_blanks(char str[], int length);

int main(){
  
  int len;
  char string[MAXLENGTH],longest[MAXLENGTH];
  while ((len= mgetline(string, MAXLENGTH)) > 0){
    remove_trailing_blanks(string,len); 
     
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

void remove_trailing_blanks(char str[], int length){
    int i=length-2,new_length=0,k,trailing_chara_length=0;
    printf("\nEntered string is \t%s\n",str);
    printf("Length of enterd string\t%d\n\n",length-1);
    k=1;
    while(k>0){
      if((str[i]==' ')||( str[i]=='\t')){
        i--;
        trailing_chara_length++;
      }
      else if(str[i]!=' ' || str[i]!='\t'){
        k=0;
      } 
    }
    new_length=i;
    printf("The new string\n");
    for(i=0;i<=new_length;i++){ 
       printf("%c", str[i]);
    }
    printf("\nLength of new string\t%d\n",i);
    printf("Number of trailing characters\t%d\n", trailing_chara_length);
  
}
