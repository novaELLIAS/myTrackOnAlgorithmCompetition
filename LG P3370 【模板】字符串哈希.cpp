#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <cstring>
#include <algorithm>

using std::sort;

#define Re register
#define maxn 10001
#define ull unsigned long long
#define modn 131ul

static char s[1501];
unsigned long long dat[maxn];

signed main ()
{
	register int n, len; scanf ("%d", &n);
	register int i, j;
	register ull now = 1ul;
	for (i = 1; i <= n; ++ i)
	{
		scanf ("%s", s); len = strlen(s);
		for (j = 0; j ^ len; ++ j)
			now = now * modn + s[j];
		dat[i] = now, now = 1ul;
	} sort (dat + 1, dat + n + 1);
	register int cnt = 1;
	for (Re int i = 2; i <= n; ++ i)
		cnt += (dat[i]^dat[i-1]? 1:0);
	return printf ("%d", cnt), 0;
}
