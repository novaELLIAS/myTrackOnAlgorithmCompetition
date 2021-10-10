#include <stdio.h>

typedef struct node;
typedef node *tree;
struct node {
	char data;
	tree lchild,rchild;
};
bool first=true;
tree root;

void grow_order(tree &bt) {
	char ch;
	ch=getchar();
	if(ch!='.') {
		bt=new node;
		bt->data=ch;
		grow_order(bt->lchild);
		grow_order(bt->rchild);
	} else bt=NULL;
}
void inorder(tree bt) {
	if(bt) {
		inorder(bt->lchild);
		printf("%c",bt->data);
		inorder(bt->rchild);
	}
}
void postorder(tree bt) {
	if(bt) {
		postorder(bt->lchild);
		postorder(bt->rchild);
		printf("%c",bt->data);
	}
}
int main(void) {
	grow_order(root);
	inorder(root);
	printf("\n");
	postorder(root);
}
