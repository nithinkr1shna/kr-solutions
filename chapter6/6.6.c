#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define HASHSIZE 101
#define SYMBOLSIZE 50
#define BUFSIZE 50
#define MAXWORD 100
#define IN 1
#define OUT 0

struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
 };

int mgetword(char *, int);
int getch(void);
void ungetch(int );
struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *);
unsigned hash(char *);
static struct nlist *hashtab[HASHSIZE];
char *s_dup(char *);
struct nlist *undef(char *, char *);


int main(){

  char name[MAXWORD],defn[MAXWORD],word[MAXWORD];
  struct nlist *result;
  while(mgetword(word,MAXWORD)!= EOF){

    if(strcmp(word,"#define")==0){

      mgetword(name,MAXWORD);
      mgetword(defn,MAXWORD);
      install(name,defn);
      result = lookup(name);
      printf("%s %s\n", result->name, result->defn);
    }
  }

}
struct nlist *install(char *name, char *defn){

  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) { /* not found */
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = s_dup(name)) == NULL){ 
      return NULL;
    }
    hashval = hash(name);
    np->next = hashtab[hashval];
    hashtab[hashval] = np;
  } else{ /* already there */
    printf("Definition overwritten\n");
    free((void *) np->defn); /*free previous defn */
   }
  if ((np->defn = s_dup(defn)) == NULL)
    return NULL;

  return np;
}

struct nlist *lookup(char *s){

  struct nlist *np;
  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0){
       return np; /* found */
    } 
  printf("\nEntry not found\n");
  return NULL; /* not found */
}


struct nlist *undef(char *name, char *defn){

    struct nlist *np;
    np = lookup(name);
    if(np != NULL){
     
      if((np->next)!= NULL){
	np->next = np->next->next;
	np = np->next;
      }else{
        hashtab[hash(name)] = NULL;
	free((void *) np);
      }
     printf("\n%s\t%s is deleted\n",name,defn);
  }else{
    printf("no definition matches\n");
  }

}

unsigned hash(char *s){

  unsigned hashval;
  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;

  return hashval % HASHSIZE;
}

char *s_dup(char *s){

  char *p;
  p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}

char buf[BUFSIZE];
int bufp=0;

int getch(void){
  
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}


int mgetword(char *word, int lim){
  int c,d,counter=0;
  char *w = word;
  int comment,directive,string;
  comment = directive= string =OUT;
  
  while(isspace(c=getch())){
    ;    
  }

  // checks for comment
  if(c= '/'){
    if((d=getch())=='*')
       comment = IN;
  }
  else{
      comment = OUT;
      ungetch(d);
  }
    
  //checks for strings
    
  if(c=='\"'){
    string = IN;
  }
  
  if(c =='#')
    directive = IN;

  if (comment == OUT && string == OUT && directive == OUT) {

        if (c != EOF)
            *w++ = c;

        if (!isalnum(c) && c !='_' ) {
            *w = '\0';
            return c;
        }

        for ( ; --lim > 0; w++) {
            *w = getch();
            if (!isalnum(*w) && *w != '_') {
                ungetch(*w);
                break;
            }
        }
        *w = '\0';
        return word[0];
    }
    else if ( comment == IN) {
        *w++ = c;
        *w++ = d;

        while ((*w++ = c = getch())) {
            if ( c == '*' ) {
                if ( (c = getch()) == '/' ) {
                    *w++ = c;
                    comment = OUT;
                    break;
                } else {
                    ungetch(c);
                }
            }
        }
        *w = '\0';

    }
    else if ( string == IN) {
        *w++ = c;
        while ((*w++ = getch()) != '\"') {
            if ( *w == '\\')  /* Take care of escaped quotes */
                *w++ = getch();
        }
        string = OUT;
        *w = '\0';
    }
    else if (directive == IN) {
        *w++ = c;
        while ((*w++ = getch()) != ' ') {
            if ( c == '\\') { /* Take care of continuation line escape */
                *w++ = getch();
            }
        }

        directive = OUT;
        *w = '\0';
    }

    return c;

}
