#include<stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20

float fahrenheit_to_celsius(float fahrenheit);

int main(){
  float fahrenheit;
  printf("\n\nFahrenheit-Celsius Table\n\n");
  for(fahrenheit=UPPER; fahrenheit>=LOWER; fahrenheit= fahrenheit-STEP){
    fahrenheit_to_celsius(fahrenheit);
  }
}


float fahrenheit_to_celsius(float fahr){
  
  printf("%6.0f %12.1f\n", fahr, (5.0/9.0)*(fahr-32.0));
  }

