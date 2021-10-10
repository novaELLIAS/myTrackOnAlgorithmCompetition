#pragma G++ optimize (3)
#pragma GCC optimize (3)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>

#define maxn 1001
#define Re register

#define gc() getchar()
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0' && c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}

int main ()
{
	register int n, in, sum = 0, max = -1;
	while (scanf ("%d", &n) != EOF)
	{
		sum = 0, max = -1;
		while (n --) in = read (), sum += in, max = in>max? in:max;
		printf ("%.1lf\n", ((sum-max)<max? (1.0*(sum-max)):(1.0*sum/2)));
	}
	
	return 0;
}
