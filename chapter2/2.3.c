#include<stdio.h>
#define MAX 50
#define YES 1
#define NO 0

int mgetline(char line[],int maxline);
int htoi(char string[], int length);

int main(void)
{
    char line[MAX];
    int value,len;
    len =mgetline(line,MAX);
    value=htoi(line, len-1);

    printf("The value of %sis%d\n",line,value);
    
    return 0;
}

int mgetline(char s[],int lim)
{
    int c,i;

    for(i=0;i<lim-1 &&(c=getchar())!=EOF && c!='\n';++i)
        s[i] =c;
    if(c=='\n')
    {
        s[i] =c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

int htoi(char s[], int length){
  int hexdigit,i,inhex,n;
  i=0;
    n = 0;
    inhex = YES;

    for(;inhex==YES;++i)
    {
        if(s[i] >='0' && s[i] <='9')
            hexdigit= s[i] - '0';
        else if(s[i] >='a' && s[i] <='f'){
	  hexdigit= s[i] -'a' + 10;
	  printf("%d",hexdigit);
	}
        else if(s[i] >='A' && s[i] <='F')
            hexdigit= s[i] -'A' + 10;
        else
            inhex = NO;
        
        if(inhex == YES)
            n = 16 * n + hexdigit;
    }
    return n;

}
