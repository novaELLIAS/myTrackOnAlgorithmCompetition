#pragma G++ optimize (3)

#include <cstdio>
#include <cstring>

#define Re register
#define maxn 100001
#define dmax 200001

inline const int& min (const int& a, const int& b) {return a<b? a:b;}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}

static char in[maxn], s[dmax];
int maxlen[dmax], ll[dmax], rr[dmax];

signed main ()
{
	scanf ("%s", in);
	register int len = strlen (in) << 1;
	for (Re int i = 0; i <= len; ++ i) s[i] = i&1? in[i>>1]:'$';
	register int rm = 0, mid = 0;
	for (Re int i = 0; i <= len; ++ i)
	{
		if (rm > i) maxlen[i] = min (maxlen[(mid<<1)-i], rm - i);
		else maxlen[i] = 1;
		while (i+maxlen[i]<=len && i-maxlen[i]>=0 && !(s[i+maxlen[i]]^s[i-maxlen[i]])) ++ maxlen[i];
		if (i + maxlen[i] > rm) rm = i + maxlen[i], mid = i;
	}
	register int pos = 0;
	for (Re int i = 0; i <= len; ++ i)
		while (pos < i + maxlen[i]) ll[pos ++] = i;
	pos = len;
	for (Re int i = len; i >= 0; -- i)
		while (pos > i - maxlen[i]) rr[pos --] = i;
	register int ans = 0;
	for (Re int i = 0; i < len; ++ i) ans = max (ans, rr[i]-ll[i]);
	printf ("%d", ans);
	return 0;
}
