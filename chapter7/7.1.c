#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define UPPER 1
#define LOWER 0

int main(int argc, char **argv){
  
  int c,flag;
  printf("USAGE:\n\t* rename to upper for uppercase\n\t* rename to lower for lowercase\n");
  printf("you've renamed to %s :\nEnter some texts:\n",argv[0]);
  if(strcmp(argv[0],"./upper")==0){
    flag = UPPER;
  }
  else if(strcmp(argv[0], "./lower")==0){
    flag = LOWER;
  }
  
  while((c=getchar())!=EOF){
    if(flag == 1)
      putchar(toupper(c));
    else if(flag == 0)
      putchar(tolower(c));
  }
return 0;
}
