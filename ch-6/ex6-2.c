#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXVAR 100

struct tnode {
	char *vname;
	int count;
	struct tnode *left;
	struct tnode *right;
};
int n_chars = 6;

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getvar(char *, int);

int main(int argc, char *argv[])
{
	// check for cmd arg
	// read variables (line by line)
	// store in tree

	if(argc > 1 && *argv[1] == '-')
		n_chars = atoi(argv[1] + 1);

	struct tnode *root;
	char vname[MAXVAR];

	root = NULL;
	while(getvar(vname, MAXVAR) != EOF){
		if(isalpha(vname[0]))
			root = addtree(root, vname);
	}
	treeprint(root);
	return 0;

}

int getvar(char *vname, int maxvr)
{
	int c, getch(void);
	void ungetch(int);
	char *v = vname;

	while(isspace(c = getch()))
		;
	if(c != EOF)
		*v++ = c;
	if(!isalpha(c)){
		*v = '\0';
		return c;
	}

	for( ; --maxvr > - 0; v++){
		if(!isalnum(*v = getch())){
			ungetch(*v);
			break;
		}
	}

	*v = '\0';
	return vname[0];

}

int bufc;
int state = 0;
int getch(void)
{
	int c;
	if(state != 0){
		c = bufc;
		state = 0;
	} else
		c = getchar();
	return c;
}

void ungetch(int c)
{
	if(state != 0)
		printf("error: char buffer full");
	else{
		bufc = c;
		state = 1;
	}
}

struct tnode *talloc(void);
char *strdupe(char *);

struct tnode *addtree(struct tnode *p, char *v)
{
	int cond;
	if(p == NULL){ // reached empty node
		p = talloc();
		p->vname = strdup(v);
		p->count = 1;
		p->left = p->right = NULL;
	} else if((cond = strncmp(v, p->vname, n_chars)) == 0) // var matches current node
		p->count++;
	else if(cond < 0) // continue down left node
		p->left = addtree(p->left, v);
	else // continue down right node
		p->right = addtree(p->right, v);
	return p;
}

void treeprint(struct tnode *p)
{
	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->vname);
		treeprint(p->right);
	}
}

struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdupe(char *s)
{
	char *p;
	p = (char *) malloc(strlen(s)+1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}
