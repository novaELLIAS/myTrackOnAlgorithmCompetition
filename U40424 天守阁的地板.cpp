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
	register long long x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (long long x) {write (x); putchar ('\n');}

typedef long long ll;
#define Re register
#define maxn 1000000
#define modn 19260817

long long dp[maxn];

inline long long poww (long long a, long long b)
{
	register long long ret = 1;
	while (b)
	{
		if (b & 1) ret = ret * a % modn;
		b >>= 1, a = a * a % modn;
	}
	return ret;
}

int main ()
{
	register long long _ = read (), n, ans, tans, tmp, pss, las;
	while (_ --)
	{
		n = read (), ans = 1ll, tans = 1ll, tmp = n << 1;
		for (Re long long i = n; i; -- i)
		{
			dp[i] = (n / i) * (n / i);
			for (Re long long j = i << 1; j <= n; j += i) dp[i] -= dp[j];
			tans = tans * poww (i * i % modn, dp[i]) % modn;
		}
		
		for (Re long long i = n; i; -- i) ans = ans * poww (i, tmp) % modn;
		
		writelen (ans * poww (tans, modn - 2) % modn);
	}
	return 0;
}
