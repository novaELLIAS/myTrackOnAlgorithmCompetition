#include <stdio.h>

int f,ste,biginn=1,maxn;
int mapp[1501][1501];
int degree[1501];
int road[1501];

void INPUT() {
	scanf("%d",&f);
	int x,y;
	for(int i=1; i<=f; i++) {
		scanf("%d%d",&x,&y);
		mapp[x][y]++;
		mapp[y][x]++;
		degree[x]++;
		degree[y]++;
		maxn=x>maxn? x:maxn;
		maxn=y>maxn? y:maxn;
	}
}
void FINDSTART() {
	for(int i=1; i<=maxn; i++) {
		if(degree[i]%2!=0) {
			biginn=i;
			break;
		}
	}
}
void SEARCH(int x) {
	for(int i=1; i<=maxn; i++) {
		if(mapp[x][i]) {
			mapp[x][i]--;
			mapp[i][x]--;
			SEARCH(i);
		}
	}
	road[++ste]=x;
}
void OUTPUT() {
	for(int i=ste; i>=1; i--) printf("%d\n",road[i]);
}
int main() {
	INPUT();
	FINDSTART();
	SEARCH(biginn);
	OUTPUT();
}
