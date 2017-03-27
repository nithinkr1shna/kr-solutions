#include<stdio.h>
#include<string.h>
#define MAXSIZE 500

int main(int argc , char **argv){

  char line1[MAXSIZE],line2[MAXSIZE];
  if(argc<3)
    printf("Provide two files as arguments\n");
  else{
    printf("\nThis is a program %s which compares two files\n", argv[0]);
    FILE *fp1,*fp2;
    fp1 =fopen(argv[1],"r");
    fp2 = fopen(argv[2],"r");
    while(!feof(fp1) || !feof(fp2)){
    fgets(line1, MAXSIZE, fp1);
    fgets(line2, MAXSIZE, fp2);
      
      if(strcmp(line1,line2) != 0){
	printf("line1: %s\nline2: %s",line1,line2);
	break;
      }else
	printf("same\n");
      
    }
  }
}
