#include<stdio.h>
int main(){
  float fahrenheit, celsius,lower, upper, step;
  printf("\n\nFahrenheit-Celcius Table\n\n");
  for(fahrenheit=300; fahrenheit>=0; fahrenheit= fahrenheit-20){
    celsius = (5.0/9.0)*(fahrenheit-32.0);
    printf("%6.0f %12.1f\n", fahrenheit, celsius);
  }
}
