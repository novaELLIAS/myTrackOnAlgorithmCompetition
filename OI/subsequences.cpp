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

typedef long long ll;
#define Re register
#define maxn 100011
#define maxk 13
#define lowbit(x) ((x)&(-x))

long long dp[maxk][maxn];
int n;

inline void add (register int pox, register int pok, register ll val)
{
	while (pox <= n) dp[pok][pox] += val, pox += lowbit(pox);
}
inline ll ask (register int pox, register int pok)
{
	register ll ret = 0ll;
	while (pox) ret += dp[pok][pox], pox -= lowbit(pox);
	return ret;
}

int main ()
{
	freopen ("subsequences.in", "r", stdin);
	freopen ("subsequences.out","w",stdout);
	
	n = (int) read (); add (1, 0, 1);
	register int _ = n, k = (int) read ();
	register long long in, ans = 0, tmp;
	
	while (_ --)
	{
		in = read ();
		for (Re int i = 1; i <= k; ++ i)
		{
			tmp = ask (in, i - 1);
			add (in + 1, i, tmp);
		}
		tmp = ask (in, k); add (in + 1, k + 1, tmp);
		ans += tmp;
	}
	
	printf ("%I64d", ans);
	
	return 0;
}
