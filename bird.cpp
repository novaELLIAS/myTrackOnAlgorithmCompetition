#pragma GCC optimize("Ofast")

#include "iostream"
#include "stdio.h"
#include "string.h"
#include "algorithm"

using namespace std;

#define maxn 10010
#define maxm 1010
#define inff 0x3f3f3f3f
#define rint register int

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

struct node {
	int p, l, h;
} tube[maxn];

inline bool cmp (node aa, node bb) {
	return aa.p < bb.p;
}

int n, m, k, p, l, h;
int ex[maxm], dp[maxm], tubecnt = 1;
int exh;
int uupp[maxn], down[maxn];
bool extube, cando;
int tubeover, ans = inff;

int main () {
	freopen ("bird.in", "r", stdin);
	freopen ("bird.out", "w", stdout);
	
	n = read (), m = read (), k = read ();
	for (rint i = 1; i <= n; i ++) uupp[i] = read (), down[i] = read ();
	for (rint i = 1; i <= k; i ++) tube[i].p = read (), tube[i].l = read (), tube[i].h = read ();
	sort (tube + 1, tube + k + 1, cmp);

	for (rint i = 1; i <= n; i ++) {
		extube = cando = false;
		memcpy (ex, dp, sizeof dp);
		memset (dp, inff, sizeof dp);
		if (i-1 == tube[tubecnt].p && tubecnt <= k) extube = true;

		for (rint j = 1; j <= m; j ++) {
			exh = j - uupp[i];
			if (exh >= 0) {
				if (!extube || (exh > tube[tubecnt].l && exh < tube[tubecnt].h)) dp[j] = min (dp[j], ex[exh] + 1);
				dp[j] = min (dp[j], dp[exh] + 1);
				if (dp[j] != inff) cando = true;
			}

			if (m - j <= uupp[i]) {
				if (!extube || (j > tube[tubecnt].l && j < tube[tubecnt].h)) dp[m] = min (dp[m], ex[j] + 1);
				dp[m] = min (dp[m], dp[j] + 1);
				if (dp[m] != inff) cando = true;
			}
		}
		
		for (rint j = m - down[i]; j >= 1; j --) {
			exh = j + down[i];
			if (!extube || (exh > tube[tubecnt].l && exh < tube[tubecnt].h)) dp[j] = min (dp[j], ex[exh]);
		}
		
		if (extube) {
			tubecnt ++;
			if (tubecnt > k) tubecnt = k + 1;
			if (cando) tubeover ++;
			else {
				printf ("0\n%d", tubeover);
				return 0;
			}
		}
	}

	for (register int i = 1; i <= m; i ++) ans = min (ans, dp[i]);
	printf ("1\n%d", ans);

	return 0;
}
