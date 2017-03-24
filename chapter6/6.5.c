#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define HASHSIZE 101
#define SYMBOLSIZE 50


struct nlist { /* table entry: */
    struct nlist *next; /* next entry in chain */
    char *name; /* defined name */
    char *defn; /* replacement text */
 };

struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *);
unsigned hash(char *);
static struct nlist *hashtab[HASHSIZE];
char *s_dup(char *);
struct nlist *undef(char *, char *);
void question(void );

int main(){
    char name[50],defn[50];
    int choice=0;
    printf("Use cntrl-c to break from the program\n");
   
    while(1){
      question();
      scanf("%d",&choice);
      printf("Enter the name\n");
      scanf("%s\n",name);
      printf("Enter the definition");
      scanf("%s",defn);
      if(choice == 1){
        install(name, defn);
      }
      else if(choice == 2){
        undef(name, defn);
      }else
	printf("Enter a correct choice\n");
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

void question(){

   printf("ente\n1 for adding definition\n2 for deleting definition\n");
}
