#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <cstring>

using namespace std;

#define Re register
#define maxn 10
#define modn 2009

struct node {
	int dat[91][91];
} zero, ori;
int siz;

inline node operator * (register node a, register node b)
{
	node ret = zero;
	for (Re int i = 1; i ^ siz; i ++)
	{
		for (Re int j = 1; j ^ siz; j ++)
		{
			for (Re int k = 1; k ^ siz; k ++)
			{
				ret.dat[i][j] = (ret.dat[i][j] + a.dat[i][k] * b.dat[k][j] % modn) % modn;
			}
		}
	}
	return ret;
}

inline node poww (register int b)
{
	node ret = zero;
	for (Re int i = 1; i ^ siz; i ++) ret.dat[i][i] = 1;
	while (b)
	{
		if (b & 1) ret = ret * ori;
		b >>= 1; ori = ori * ori;
	}
	return ret;
}

int main ()
{
	register int n, _;
	scanf ("%d %d", &n, &_);
	siz = n * 9 + 1;
	register char s[11];
	for (Re int i = 0; i ^ n; i ++)
	{
		for (Re int j = 1; j ^ 9; j ++)
		{
			ori.dat[9 * i + j][9 * i + j + 1] = 1;
		}
	}
	for (Re int i = 1; i ^ siz; i ++)
		for (Re int j = 1; j ^ siz; j ++)
			zero.dat[i][j]=0;
	for (Re int i = 0; i ^ n; i ++)
	{
		scanf ("%s", s);
		for (Re int j = 0; j ^ n; j ++)
		{
			if (s[j] ^ '0')
			ori.dat[9 * i + (s[j] ^ '0')][9 * j + 1] = 1;
		}
	}
	printf ("%d", poww (_).dat[1][n * 9 - 8]);
}
