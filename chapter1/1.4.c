#include<stdio.h>
int main(){
  float fahrenheit, celsius,lower, upper, step;
  printf("\n\nCelsius-Fahrenheit Table\n\n");
  lower=0;
  upper=300;
  step=20;

  celsius = lower;
  while(celsius <= upper){
    fahrenheit = (celsius*(9.0/5.0))+32.0;
    printf("%6.0f %12.1f\n", celsius, fahrenheit);
    celsius += step;
  }
}
