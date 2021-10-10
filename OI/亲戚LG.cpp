#include <stdio.h>

int father[500001];
bool ans[500001];
int m,n,p,x,y;

int find(int x) {
	int k=x;
	while(father[x]!=x) x=father[x];
	while(father[k]!=x) {
		int temp=father[k];
		father[k]=x;
		k=temp;
	}
	return x;
}
void unionn(int x,int y) {
	father[y]=x;
}
int main(void) {
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1; i<=n; i++) father[i]=i;
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		int posx=find(x);
		int posy=find(y);
		if(posx!=posy) unionn(posx,posy);
	}
	for(int i=1; i<=p; i++) {
		scanf("%d%d",&x,&y);
		if(find(x)==find(y)) ans[i]= true;
	}
	for(int i=1; i<=p; i++){
		if(ans[i]==true) printf("Yes\n");
		else printf("No\n");
	}
}
