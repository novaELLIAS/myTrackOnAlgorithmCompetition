#include <stdio.h>
#include <stdlib.h>

int n,goal,ans;
int data[101],lchild[101],rchild[101];

void INPUT(){
	scanf("%d%d",&n,&goal);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&data[i],&lchild[i],&rchild[i]);
}
void SEARCH(int root){
	if(lchild[root]) SEARCH(lchild[root]);
	ans++;
	if(data[root]==goal){
		printf("%d",ans);
		exit(0);
	}
	if(rchild[root]) SEARCH(rchild[root]);
}
int main(void){
	INPUT();
	SEARCH(1);
}
