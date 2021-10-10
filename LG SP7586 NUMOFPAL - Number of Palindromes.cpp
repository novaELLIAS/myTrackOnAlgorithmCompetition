#pragma G++ optimize (3)

#include <cstdio>
#include <cstring>

#define Re register
#define maxn 1001
#define maxl 2001

inline const int& min (const int& a, const int& b) {return a<b? a:b;}
inline const int& max (const int& a, const int& b) {return a>b? a:b;}

char in[maxn], s[maxl];
int ans[maxl];

signed main ()
{
	scanf ("%s", in);
	register int len = strlen(in) << 1;
	for (Re int i = 0; i <= len; ++ i) s[i] = (i&1)? in[i>>1]:'$';
	register int rmx = 0, mid = 0;
	for (Re int i = 0; i <= len; ++ i)
	{
		if (rmx > i) ans[i] = min (ans[(mid<<1)-i], rmx - i);
		else ans[i] = 1;
		while (i+ans[i]<=len && i-ans[i]>=0 && !(s[i+ans[i]] ^ s[i-ans[i]])) ++ ans[i];
		if (i + ans[i] > rmx) rmx = i + ans[i], mid = i;
	}
	register int ret = 0;
	for (Re int i = 1; i <= len; ++ i) ret += ans[i] >> 1;
    printf ("%d", ret);
    return 0;
}
