#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS], *p1 = buf, *p2 = buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = false;
	while (c < '0' || c > '9') {if (c == '-') m = true; c = gc();}
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
inline const long long& max (const long long& a, const long long& b) {return a>b? a:b;}

#define Re register
#define maxn 100001

typedef long long ll;
ll dat2[maxn], dat1[maxn], dp1[maxn], dp2[maxn];

inline ll query (ll *a, ll *dp, register int n)
{
	register ll ret = -0x3f3f3f3f, now = 0;
	for (Re int i = 1; i <= n; ++ i) dp[i] = max (a[i], dp[i-1] + a[i]), ret = max (ret, dp[i]);
	return ret;
}

signed main ()
{
	freopen ("circle.in", "r", stdin);
	freopen ("circle.out","w",stdout);
	
	register int n = (int) read (); register long long sum = 0;
	for (Re int i = 1; i <= n; ++ i) dat1[i] = read (), dat2[i] = -dat1[i], sum += dat1[i];
	
	register long long ans1 = query (dat1, dp1, n);
	register long long ans2 = sum + query (dat2, dp2, n);
	
	printf ("%I64d", ans1>ans2? ans1:ans2);
	
	return 0;
}
