#include<stdio.h>

int main(){
  int  character_freq[26];
  int c,i,count=0;
  
  for(i=0;i<26;i++){
    character_freq[i]==0;
   }
  while((c=getchar())!=EOF){
    putchar(c);
    if(c>='a' &&  c<='z'){
      character_freq[c-97]++;
      
    }
    else if(c>='A' && c<= 'Z'){
      character_freq[c-65]++;
    }
    
    if(c=='\n'){
      
      for(i=0;i<26;i++){
	if(character_freq[i]!=0){
	  printf("%c\t\t",i+97);
	  count=character_freq[i];
	  while(count >0){
	    printf("*");
	    count--;
	  }
	  printf("\n");
	  
	}
      }
      
      for(i=0;i<26;i++){
	character_freq[i]=0;
      }
      count=0;
     
    }
    
  }

  
}
