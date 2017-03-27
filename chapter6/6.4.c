#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define MAXWORD 500
#define YES 1
#define NO 0

void make_entry(char *,int line_no);
void to_words(char *, int line_no);
struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
void filter_to_alpha(char *, int line_no);
struct tnode *talloc(void);
int numcmp(const char *s1, const char *s2);
char *s_dup(char *);

struct tnode{

  char *word;
  int line_no;
  int count;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *root;


int main(){

  FILE *fp;
  char *line = malloc(MAXWORD);
  int line_no;
  fp = fopen("document.txt","r");
  while((fgets(line, MAXWORD, fp)) != NULL){
    //printf("%s",line);
    line_no++;
    to_words(line,line_no);
  }
  treeprint(root);
  return 0;
}

void to_words(char *line,int line_no){
  int count =0;
  char *each_word;
  each_word = strtok(line," ");// splits line based on a delimiter
  while(each_word != NULL){
    filter_to_alpha(each_word,line_no);
    each_word = strtok(NULL, " ");
    
  }
}


void filter_to_alpha(char *word, int line_no){
  int len = strlen(word),i=0,counter=0,len2;
  len2=len;
  char word_dup[MAXWORD];
  strcpy(word_dup,((const char *) word));
  while(len-- >0){
    if(isalpha(word[i]))
      counter++;
    i++;
  }
  //printf("%d\t",len2);
  //printf("%d\n",counter);
    if(counter == len2){
      //printf("%s\t%d\t\t",word_dup,line_no);
      make_entry(word_dup,line_no);
    }
  

}
void make_entry(char *word, int line_no){

  //printf("%s\t%d\t\t",word,line_no);
  root =addtree(root, word, line_no);
}

struct tnode *addtree(struct tnode *p, char *w, int line_no ){
  int len;
  int cond;
  if(p == NULL){

    p = talloc();
    p-> word = s_dup(w);
    p->left = p->right = NULL;
  }
  else if ((cond = strcmp(w, p->word)) == 0){
    p->count++ ;/* repeated word */
  }
    else if (cond < 0) /* less than into left subtree */
      p->left = addtree(p->left, w,line_no);
    else /* greater than into right subtree */
      p->right = addtree(p->right, w,line_no);
  return p;
}

void treeprint(struct tnode *p){
  int len=0;
  if (p != NULL) {
    treeprint(p->left);
    printf("%s\t", p->word);
    
    printf("%d\n",p->count);
    treeprint(p->right);
 }
}
struct tnode *talloc(void){
  return (struct tnode *) malloc(sizeof(struct tnode));
}

int numcmp(const char *s1, const char *s2){

  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

char *s_dup(char *s){

  char *p;
  p = (char *) malloc(strlen(s)+1); /* +1 for '\0' */
  if (p != NULL)
    strcpy(p, s);
  return p;
}
 
void mqsort(struct tnode *p){

  
}

