#include <stdio.h>

bool mapp[1001][1001],judge[1001];
int degree[1001];
int road[1001];
int n,m,ste,biginn=1;

void INPUT() {
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1; i<=m; i++) {
		scanf("%d%d",&x,&y);
		mapp[x][y]=mapp[y][x]=true;
		degree[x]++;
		degree[y]++;
	}
}
void FINDSTART() {
	for(int i=1; i<=n; i++) {
		if(degree[i]%2!=0) {
			biginn=i;
		}
	}
}
void SEARCH(int x) {
	//if(judge[x]==true) return;
	//judge[x]=true;
	//road[++ste]=x;
	for(int i=1; i<=n; i++) {
		if(mapp[x][i]==true) {
			mapp[x][i]=mapp[i][x]=false;
			SEARCH(i);
			//mapp[x][i]=mapp[i][x]=true;
		}
	}
	road[++ste]=x;
	//judge[x]=false;
}
void OUTPUT() {
	for(int i=1; i<=ste; i++) printf("%d ",road[i]);
}
int main(void) {
	INPUT();
	FINDSTART();
	SEARCH(biginn);
	OUTPUT();
}
