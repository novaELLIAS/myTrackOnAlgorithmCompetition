#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include <ctype.h>

#define ll long long
#define rint register int
#define modn 999991
#define maxm 1000001
#define maxn 101

int n, m, ans, ret;
int a[maxn], out[maxm];

inline int read () {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

inline int nicoread () {
	int x = 0; char c = getchar(); bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = (x * 10 + c - '0') % modn, c = getchar();
	if (m) return -x;
	else return x;
}

inline bool check (int x) {
	ret = a[n];
	for (rint i = n; i >= 1; i --) ret = (x*ret + a[i-1]) % modn;
	return ret == 0;
}

int main () {
	//freopen ("equation.in","r",stdin);
	//freopen ("equation.out", "w", stdout);
	n = read (), m = read ();
	for (rint i = 0; i <= n; i ++) a[i] = nicoread ();

	for (rint i = 1; i <= m; i ++) if (check (i)) out[++ ans] = i;

	printf ("%d\n", ans);
	for (rint i = 1; i <= ans; i ++) printf ("%d\n", out[i]);

	return 0;
}
