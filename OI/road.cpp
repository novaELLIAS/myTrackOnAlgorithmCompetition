#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "queue"
#include "vector"

#define maxn 10001
#define maxm 200000
#define rint register int

using namespace std;

inline int read () {
	int sign = 1, n = 0;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') sign = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		n = (n*10) + c-'0';
		c = getchar();
	}
	return sign*n;
}

int n, m, sta, end, xx, yy;
int size, fro;
int degr[maxn], degc[maxn], dis[maxn];
vector <int> e[maxn];
bool check[maxn];
queue <int> que;

int main () {
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);

	n = read (), m = read ();
	for (rint i = 1; i <= m; i ++) {
		xx = read (), yy = read ();
		if (xx != yy) {
			e[yy].push_back (xx);
			degr[xx] ++;
		}
	}
	sta = read (), end = read ();

	que.push (end);
	while (!que.empty()) {
		fro = que.front(), que.pop ();
		size = e[fro].size();
		for (rint i = 0; i < size; i ++) {
			if (!degc[e[fro][i]]) que.push (e[fro][i]);
			degc[e[fro][i]] ++;
		}
	}
	for (rint i = 1; i <= n; i ++) if (degr[i] == degc[i]) check[i] = true;

	while (!que.empty()) que.pop();
	que.push(end);
	while (!que.empty()) {
		fro = que.front(), que.pop();
		size = e[fro].size();
		for (rint i = 0; i < size; i ++) {
			if (check[e[fro][i]]) {
				que.push(e[fro][i]);
				check[e[fro][i]] = false;
				dis[e[fro][i]] = dis[fro] + 1;
			}
		}
	}

	if (dis[sta] == 0) printf ("-1");
	else printf ("%d", dis[sta]);

	return 0;
}
