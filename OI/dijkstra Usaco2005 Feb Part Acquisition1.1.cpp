#include <stdio.h>
#include <string.h>
#define INF 10000005

int mapp[1005][1005],dis[1005],vis[1005];
int n,k;

void DICKSTRA() {
	for(int i = 1; i <= k; i ++) {
		dis[i] = mapp[1][i];
	}
	vis[1] = 1;
	int min,v;
	for(int i = 1; i < k; i ++) {
		min = INF;
		v = 1;
		for(int j = 1; j <= k; j ++) {
			if(!vis[j] && dis[j] < min) {
				min = dis[j];
				v = j;
			}
		}
		vis[v] = 1;
		for(int j = 1; j <= k; j ++) {
			if(!vis[j] && dis[j] > dis[v] + mapp[v][j]) {
				dis[j] = dis[v] + mapp[v][j];
			}
		}
	}
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= k; j ++) {
			mapp[i][j] = INF;
		}
		vis[i] = 0;
	}
	memset(mapp,INF,sizeof(mapp));
	int u,v;
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d",&u,&v);
		mapp[u][v] = 1;
	}
	DICKSTRA();
	if(dis[k] == INF) printf("-1");
	else printf("%d",dis[k]+1);
}
