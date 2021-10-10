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

static char buf[1<<14],*p1=buf,*p2=buf;	
inline char gc() {
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,1<<14,stdin),p1==p2)?EOF:*p1++;
}
inline long long read () {
	register long long x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc();
	while (c>='0' && c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return x;
}

typedef long long ll;

signed main ()
{
	register int _ = (int) read (), n;
	register long long sum, max, in;
	while (_ --) {
		n = (int) read(), sum = 0ll, max = -1ll;
		while (n --) in = read (), sum += in, max = in > max? in : max;
		printf ("%.1lf\n", ((sum-max)<max? (1.0*(sum-max)):(1.0*sum/2)));
	} return 0;
}
