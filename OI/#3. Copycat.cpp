#pragma GCC optimize (2)
#pragma G++ optimize (2)
#pragma GCC optimize (3)
#pragma G++ optimize (3)
#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>

using namespace std;

#define gc(x) getchar(x)
#define pt(x) putchar(x)

signed main ()
{
	freopen ("copycat.in", "r", stdin);
	freopen ("copycat.out","w",stdout);
	register char c; register int n; scanf ("%d", &n);
	while ((c=gc()) != EOF) pt(c);
	return 0;
}
