#include<stdio.h>
#include<string.h>

#define MAXSIZE 500

void pattern_search(char *, char *);
void get_file_pattern();

int main(int argc, char **argv){
    char file_name[MAXSIZE];
    char pattern[MAXSIZE];
    if(argc > 1){
      pattern_search(argv[1],argv[2]);
    }else{
      
    }
    
}


void pattern_search(char *file, char *pattern){

  FILE *fp;
  char line[MAXSIZE];
  int counter=0;
  fp = fopen(file, "r");
  printf("File    : %s\n",file);
  printf("pattern : %s\n\n",pattern);
  while(!feof(fp)){
    fgets(line,MAXSIZE,fp);
    counter++;
    if(strstr(line,pattern)){
      printf("found at line no:%d\n",counter);
    }else{
      printf("NO Match\n");
      get_file_pattern();
    }
      
  }
  fclose(fp);
}

void get_file_pattern(){
  char file_name[MAXSIZE],pattern[MAXSIZE];
  printf("Enter the name of the file to search the pattern\n");
  scanf("%s",file_name);
  printf("Enter the pattern to search for\n");
  scanf("%s",pattern);
  pattern_search(file_name, pattern);
}
