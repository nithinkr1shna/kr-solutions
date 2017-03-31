#include<stdio.h>
#include<stdlib.h>

void* mycalloc(int n, size_t size);

int main(){

  int n;
  printf("Enter the size of array\n");
  scanf("%d",&n);
  int *A = (int *)mycalloc(n,sizeof(int));
  for(int i=0;i<n;i++){
    A[i]= i+1;
    
  }
  for(int i=0;i<n;i++)
    printf("%d\t",A[i]);
  
  printf("\n");
}

void* mycalloc(int n, size_t size){

  return malloc(n*size);
}
