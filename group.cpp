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

typedef long long ll;
#define Re register
#define maxn 100001

ll dp[maxn];

int main ()
{
	freopen ("group.in", "r", stdin);
	freopen ("group.out","w",stdout);
	
	register long long in;
	register long long n = read (), max1 = -1e15, max2 = -1e15;
	
	for (Re int i = 1; i <= n; ++ i)
	{
		in = read ();
		dp[i] = max (dp[i-1], max (max1 + in, max2 - in));
		max1 = max (max1, dp[i-1] - in), max2 = max (max2, dp[i-1] + in);
	}
	
	printf ("%I64d", dp[n]);
	
	return 0;
}
