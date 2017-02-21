#include<stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(){
  printf("%u",invert((unsigned)15, 3,3));
}

unsigned invert(unsigned x, int n, int p){
  return x ^ (~(~0 << n) << (p - n));
}
