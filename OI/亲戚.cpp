#include <stdio.h>

int father[20001];
bool ans[1000001];
int m,n,p,x,y;

int read() {
	int k=0;
	char f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
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
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) father[i]=i;
	for(int i=1; i<=m; i++) {
		x=read();
		y=read();
		//scanf("%d%d",&x,&y);
		int posx=find(x);
		int posy=find(y);
		if(posx!=posy) unionn(posx,posy);
	}
	scanf("%d",&p);
	for(int i=1; i<=p; i++) {
		x=read();
		y=read();
		//scanf("%d%d",&x,&y);
		if(find(x)==find(y)) ans[i]= true;
	}
	for(int i=1; i<=p; i++) {
		if(ans[i]==true) printf("Yes\n");
		else printf("No\n");
	}
}
