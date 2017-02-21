#include<stdio.h>

int binsearch(int x, int v[], int n);

int main(){
  int i, sorted_arry[]={1,5,7,8,9,12,13,19,25,35,40};
  
  printf("%d",binsearch(9, sorted_arry, 11));
}

int binsearch(int x, int v[], int n){
  
  int low, high, mid;
  low = 0;
  high = n - 1;
  mid =(low+high)/2;
  
  while ((low<=high) && (x != v[mid])){
    mid =(low+high)/2;
    if (x > v[mid])
      low = mid + 1;
    else  
      high = mid - 1;
   
   }
  if(x==v[mid]){
    return mid;
  }
  else
    return -1;


}
