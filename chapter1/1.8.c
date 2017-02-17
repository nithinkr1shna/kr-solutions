#include<stdio.h>

int main(){
  int c;
  long int newline_count=0, tab_count=0, blankspace_count=0;
  FILE *filepointer;
  filepointer=fopen("test_file","r");
  while((c=fgetc(filepointer)) !=EOF){
    if(c=='\n')
      ++newline_count;
    if(c=='\t')
      ++tab_count;
    if(c==' ')
      ++blankspace_count;
  }
  printf("newline\t\t\%ld\ntabs\t\t%ld\nblankspace\t\t%ld\n",newline_count,tab_count,blankspace_count);
}
