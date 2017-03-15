#include<stdio.h>
#include<stdlib.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *, int *);
int  getchoice();
int check_for_error(int year, int month, int day);
int check_for_error_in_yearday(int yearday);
char *days_with_names(int month);

static char daytab[2][13] ={{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,3}};


int main(){

  getchoice();
 }

int getchoice(){
  int choice, year, month, day,yearday;
  int pday, pmonth;
  printf("1. For converting to day of year\n2. For converting to month_day\n3. For exit\n");
  scanf("%d",&choice);
  if (choice ==1){
     printf("enter the year\n");
     scanf("%d",&year);
     printf("enter the month\n");
     scanf("%d",&month);
     printf("enter the day\n");
     scanf("%d",&day);
     if(check_for_error(year,month,day) !=0)
        printf("%d",day_of_year(year, month, day));
     else{
       printf("invalid entry in month or day\n");
       getchoice();
     }

  }
  else if(choice ==2){
    printf("enter the year day\n");
    scanf("%d",&yearday);
    month_day(year, yearday, &pmonth, &pday);
    if(check_for_error_in_yearday(yearday)!=0){
      printf(" %d %d\n" ,pmonth, pday);
    }
    else{
      printf("invalid entry in yearday\n");
      getchoice();
    }
    
  }
  else if(choice==3){
    printf("you've exitted the program\n");
    exit(0);
  }else{
    printf("select a valid choice\n");
    getchoice();
  }
}
  int day_of_year(int year, int month, int day){

    int i, leap;
    char *p;
   
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = &daytab[leap][1];
    for (i = 1; i < month; i++){
      day += *p;
      p++;
      
    }
    return day;
 }

  void month_day(int year, int yearday, int *pmonth, int *pday){

    int i, leap;
    char *p;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    p = &daytab[leap][1];
    for (i = 1; yearday > *p; i++){
      yearday -= *p;
      p++;
    }
   *pmonth = i;
   *pday = yearday;
  }

int check_for_error(int year, int month, int day){

  if (month >12 || month <=0|| day >31)
    return 0;
  else
    return 1;
   
}

int check_for_error_in_yearday(int yearday){

  if(yearday>366)
    return 0;
  else
    return 1;
}


