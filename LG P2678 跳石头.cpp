#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "ctype.h"

#define maxn 50001
#define rint register int

inline int read () {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int ll, n, m, a[maxn];

inline bool nico (int x) {
	int cnt = 0, las = 0;
	for (rint i = 1; i <= n; i ++) {
		if (a[i] - las < x) cnt ++;
		else las = a[i];
	}
	if (ll - las < x) cnt ++;
	return cnt <= m;
}

int main () {
	ll = read (), n = read (), m = read ();
	for (rint i = 1; i <= n; i ++) a[i] = read ();
	int l = 1, r = ll, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (nico (mid)) l = mid + 1;
		else r = mid - 1;
	}
	printf ("%d", l - 1);
}
