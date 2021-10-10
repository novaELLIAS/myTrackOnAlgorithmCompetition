#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

long long mapp[101][101];
long long work[101][101];
long long maxl[101], maxr[101];
bool vis[101];

#define max(x,y) ((x)>(y)? (x):(y))

struct DATA {
	int name;
	long long val;
} data[101];

inline bool cmp (DATA a, DATA b) {
	return a.val<b.val;
}

signed main () {
	register int n, m, exitCnt=0;
	register long long tot = 0ll;
	scanf ("%d %d", &n, &m);
	for (register int i=1; i<=n; ++ i) {
		for (register int j=1; j<=m; ++ j) {
			scanf("%lld", &mapp[i][j]);
			if (mapp[i][j]) {
				maxl[i] = max(maxl[i], mapp[i][j]);
				++ exitCnt, tot += mapp[i][j];
			}
		}
	}
	
	//cout << "tot: " << tot << endl;
	
	for (register int j=1; j<=m; ++ j) {
		for (register int i=1; i<=n; ++ i) {
			maxr[j] = max(maxr[j], mapp[i][j]);
		} data[j] = (DATA) {j, maxr[j]};
	} std::sort(data+1, data+m+1, cmp);
	
	register long long ans = 0ll;
	register int ansCnt = 0;
	register bool validFlag = false;
	for (register int i=1; i<=n; ++ i) {
		validFlag = false;
		for (register int j=1; j<=m; ++ j) {
			if (data[j].val >= maxl[i] && !vis[data[j].name] && mapp[i][data[j].name]) {
				work[i][data[j].name] = maxl[i], vis[data[j].name] = true; validFlag = true; break;
			}
		} if (!validFlag) ans += maxl[i], ++ ansCnt;
	}
	
	register bool flag = false;
	for (register int j=1; j<=m; ++ j) {
		flag = false;
		for (register int i=1; i<=n; ++ i) {
			ans += work[i][j]; if (work[i][j]) ++ ansCnt;
		}
		for (register int z=1; z<=n; ++ z) {
			if (work[z][j] == maxr[j]) {
				flag = true; break;
			}
		} if (!flag) ans += maxr[j], ++ ansCnt;
	} ans += (exitCnt - ansCnt);
	
	return printf("%lld", tot - ans), 0;
}
