
int main(){
   for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
     s[i] = c;

   // can be written as

   for(i=0;i<lim-1;i++){
     if((c=getchar()!='\n')){
       if(c!=EOF)
	 s[i]=c;
       else
	 break;
     }
     else
       break;
   }

