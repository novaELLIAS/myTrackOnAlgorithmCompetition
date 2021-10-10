#pragma G++ optimize (3)

#include <cstdio>

#define Re register
#define maxn 31
#define modn 2017

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
    return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); //register bool m = false;
	while ((c < '0' || c > '9')/* && (c ^ '-')*/) c = gc();
	//if (c == '-') m = true, c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return /*m? -x:*/x;
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

struct matrix {
	int dat[maxn][maxn];
	int size;
	
	matrix operator * (const matrix &b) const
	{
		matrix ret; register int siz = size; ret.size = siz;
		for (Re int i = 0; i <= siz; ++ i)
			for (Re int j = 0; j <= siz; ++ j)
			{
				ret.dat[i][j] = 0;
				for (Re int k = 0; k <= siz; ++ k)
					ret.dat[i][j] = (ret.dat[i][j] + dat[i][k] * b.dat[k][j]) % modn;
			}
		return ret;
	}
	void print()
	{
		printf("\n");
		for (Re int i = 0; i <= size; ++ i)
		{
			for (Re int j = 0; j <= size; ++ j)
			{
				printf("%d ",dat[i][j]);
			}
			printf("\n");
		}
	}
} mat;

matrix qpow (matrix a, Re int t)
{
	matrix ret, base = a; register int siz = a.size; ret.size = siz;
	for (Re int i = 0; i <= siz; ++ i)
		for (Re int j = 0; j <= siz; ++ j)
			ret.dat[i][j]=0;
	for (Re int i = 0; i <= siz; ++ i) ret.dat[i][i] = 1ll;
	//ret.print();
	while (t)
	{
		if (t&1) ret = ret * base;
		base = base * base, t >>= 1;
		//ret.print();
	}
	ret.size = siz;
	//ret.print();
	return ret;
}

signed main ()
{
	register int n = read (), m = read ();
	register int fr, to; mat.size = n;
	while (m --) fr = read (), to = read (), mat.dat[fr][to] = mat.dat[to][fr] = 1;
	for (Re int i = 0; i <= n; ++ i)
		mat.dat[i][i] = mat.dat[i][0] = 1;
	//mat.print();
	mat = qpow (mat, read ());
	//mat.print();
	register int ans = 0;
	for (Re int i = 0; i <= n; ++ i) (ans += mat.dat[1][i]) %= modn;
	printf ("%d\n", ans);
	return 0;
}
