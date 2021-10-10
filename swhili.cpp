#include <cstdio>
#include <cstring>
#include <cstring>
#define INF 10000005
using namespace std;

int map[1005][1005],dis[1005],path[1005],vis[1005];
int n,k;

void PrintPath(int v) {
	if(v == 1) {
		printf("1\n");
		return ;
	} else {
		PrintPath(path[v]);
		printf("%d\n",v);
	}
}

void dijkstra() {
	for(int i = 1; i <= k; i ++) {
		dis[i] = map[1][i];
		if(i != 1 && map[1][i] < INF)
			path[i] = 1;
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
			if(!vis[j] && dis[j] > dis[v] + map[v][j]) {
				dis[j] = dis[v] + map[v][j];
				path[j] = v;
			}
		}
	}
}

int main() {
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= k; j ++) {
			map[i][j] = INF;
		}
		vis[i] = 0;
		path[i] = -1;
	}

	int u,v;
	for(int i = 1; i <= n; i ++) {
		scanf("%d%d",&u,&v);
		map[u][v] = 1;
	}

	dijkstra();

	if(dis[k] == INF) {
		printf("-1\n");
	} else {
		printf("%d\n",dis[k]+1);
		//PrintPath(k);
	}
	return 0;
}
