#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "queue"
#include "ctype.h"
#include "algorithm"

using namespace std;

#define rint register int
#define maxn 100001
#define maxm 7000001
#define inff 0x3f3f3f3f

inline int read () {
	int x = 0;
	char c = getchar();
	bool m = 0;
	while (!isdigit(c) && c != '-') c = getchar();
	if (c == '-') c = getchar(), m = 1;
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (m) return -x;
	else return x;
}

int n, m, q, u, v, t, aaa, b, a[maxn], sum;
double p;
queue <int> que[3];

inline bool cmp (int aa, int bb) {
	return aa > bb;
}

int main () {
	n = read (), m = read (), q = read (), u = read (), v = read (), t = read ();
	p = (double)u / (double) v;
	for (rint i = 1; i <= n; i ++) a[i] = read ();
	sort (a+1, a+n+1, cmp);
	for (rint i =  1; i <= n; i ++) que[0].push(a[i]);
	int last = -inff, loc = -1;
	for (rint i = 1; i <= m; i ++) {
		last = -inff, loc = -1;
		for (rint j = 0; j < 3; j ++) if (!que[j].empty() && last < que[j].front ()) last = que[j].front(), loc = j;
		que[loc].pop();
		last += sum;
		sum += q;
		aaa = (long long)last*u/v, b = last - aaa;
		aaa -= sum;
		b -= sum;
		que[1].push(aaa), que[2].push(b);
		if (!(i%t)) printf ("%d ", last);

	}

	putchar ('\n');

	for (rint i = 1; i <= n+m; i ++) {
		last = -inff, loc = -1;
		for (rint j = 0; j < 3; j ++) if (!que[j].empty()&&last < que[j].front()) last = que[j].front(), loc = j;
		que[loc].pop();
		if (!(i%t)) printf ("%d ", last + sum);
	}
}
