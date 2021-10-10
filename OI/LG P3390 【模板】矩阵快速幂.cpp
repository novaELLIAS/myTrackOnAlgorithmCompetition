#pragma G++ optimize (3)

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline long long read ()
{
	register long long x = 0; register char c = gc(); register bool m = false;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return m? -x:x;
}
static void write (long long x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writes (long long x)
{
	if (x < 0) x = -x, putchar ('-');
	write (x), putchar (' ');
}

#define maxn 101
#define Re register
typedef long long ll;
#define modn 1000000007ll

struct matrix {
	long long dat[maxn][maxn];
	int size;
	
	inline void matrix_set (matrix &a, Re long long x)
	{
		register int siz = a.size;
		for (Re int i = 1; i <= siz; ++ i)
			for (Re int j = 1; j <= siz; ++ j)
				a.dat[i][j] = x;
	}
	
	matrix operator * (const matrix &b) const
	{
		matrix ret; register int siz = size; ret.size = siz;
		for (Re int i = 1; i <= siz; ++ i)
			for (Re int j = 1; j <= siz; ++ j)
			{
				ret.dat[i][j] = 0;
				for (Re int k = 1; k <= siz; ++ k)
					ret.dat[i][j] = (ret.dat[i][j] + dat[i][k] * b.dat[k][j]) % modn;
			}
		return ret;
	}
} mat;

inline matrix qpow (matrix a, Re ll t)
{
	matrix ret, base = a; register int siz = a.size; ret.size = siz;
	for (Re int i = 1; i <= siz; ++ i) ret.dat[i][i] = 1ll;
	while (t)
	{
		if (t&1) ret = ret * base;
		base = base * base, t >>= 1;
	}
	ret.size = siz;
	return ret;
}

signed main ()
{
	register long long n = read (), k = read ();
	mat.size = n;
	for (Re int i = 1; i <= n; ++ i)
		for (Re int j = 1; j <= n; ++ j)
			mat.dat[i][j] = read ();
	mat = qpow (mat, k);
	for (Re int i = 1; i <= n; ++ i) {
		for (Re int j = 1; j <= n; ++ j)
			writes (mat.dat[i][j]);
		putchar ('\n');
	}
	return 0;
}
