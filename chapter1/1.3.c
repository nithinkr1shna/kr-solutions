#include<stdio.h>
int main(){
  float fahrenheit, celsius,lower, upper, step;
  printf("\n\nFahrenheit-Celsius Table\n\n");
  lower=0;
  upper=300;
  step=20;

  fahrenheit= lower;
  while(fahrenheit <= upper){
    celsius = (5.0/9.0)*(fahrenheit-32.0);
    printf("%6.0f %12.1f\n", fahrenheit, celsius);
    fahrenheit += step;
  }
}
