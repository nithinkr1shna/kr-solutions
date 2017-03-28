#include<stdio.h>

#define MAXPAGE 5
#define MAXLINE 500

void all_files(char *argv[], int);

int main(int argc, char **argv){

  if(argc==1)
    printf("ERROR:  Exiting...... . \n\tProvide file names as command line arguments\n\n");
    else{
      all_files(argv, argc);
    }
  
}
void all_files(char *argv[], int argc){

  FILE *fp,*fp1;
  int i=1,line_no=0,page_no=0,lines_left=0;
  char line[MAXLINE];
  fp1= fopen("new.c","w");
  for(;argc-- > 1;i++){
    fp = fopen(argv[i],"r");
    while(!feof(fp)){

      fgets(line, MAXLINE, fp);
      if(line_no == MAXPAGE){
	fprintf(fp1,"\n\n");
	line_no =0;
	page_no++;
      }
      fprintf(fp1,"%s",line);
      line_no++;
    }
    if(line_no < MAXPAGE){

      lines_left = MAXPAGE-line_no;
      while(lines_left-->0)
	fprintf(fp1,"\n");
      
    }
    
  }
  fclose(fp);
  fclose(fp1);
}
