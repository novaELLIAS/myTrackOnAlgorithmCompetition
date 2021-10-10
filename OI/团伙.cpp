#include <stdio.h>

int n,m,tot;
int s[1001];
bool mapp[1001][1001];

int find(int x) {
	int k=x;
	while(s[x]!=x) x=s[x];
	while(s[k]!=x) {
		int temp=s[k];
		s[k]=x;
		k=temp;
	}
	return x;
}
void unionn(int x,int y) {
	x=find(x);
	y=find(y);
	s[y]=x;
}
void INIT() {
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) s[i]=i;
	int x,y,p;
	for(int i=1; i<=m; i++) {
		scanf("%d%d%d",&p,&x,&y);
		if(p==0) unionn(x,y);
		else {
			mapp[x][y]=mapp[y][x]=true;
			for(int j=1; j<=n; j++) {
				if(mapp[x][j]) unionn(y,j);
				if(mapp[y][j]) unionn(x,j);
			}
		}
	}
}
int main() {
	INIT();
	for(int i=1; i<=n; i++) {
		if(s[i]==i) tot++;
	}
	printf("%d",tot);
	return 0;
}
