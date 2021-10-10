#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int INF=10000005;
int n,k;
int mapp[1001][1001];
int dis[1001],vis[1001];

void INIT() {
	scanf("%d%d",&n,&k);
	for(int i=1; i<=k;i++) {
		for(int j=1; j<=k;j++) {
			mapp[i][j]=INF;
		}
		vis[i]=0;
	}
	int x,y;
	for(int i=1; i<=n; i++) {
		scanf("%d%d",&x,&y);
		mapp[x][y]=1;
	}
}
void DICKSTRA() {
	int min=INF,v=1;
	for(int i=1;i<=k;i++) dis[i]=mapp[1][i];
	vis[1]=1;
	for(int i=1; i<k; i++) {
		min=INF;
		v=1;
		for(int j=1; j<=k; j++) {
			if(!vis[j] and dis[j]<min) {
				min=dis[j];
				v=j;
			}
		}
		vis[v]=1;
		for(int j=1; j<=k; j++) {
			if(!vis[j] and dis[j]>dis[v]+mapp[v][j]) {
				dis[j]=dis[v]+mapp[v][j];
			}
		}
	}
}
int main() {
	INIT();
	DICKSTRA();
	if(dis[k]==INF) printf("-1");
	else printf("%d",dis[k]+1);
}
