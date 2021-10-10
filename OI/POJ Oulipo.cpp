#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <cstring>

#define Re register
typedef unsigned long long ull;
typedef long long ll;
#define maxl 1000001

static char a[maxl], b[maxl];
ull hash[maxl];
const ull base = 131ul;

inline long long qpow (Re ull a, Re ull t)
{
	register long long base = a, ret = 1ll;
	while (t)
	{
		if (t&1) ret = ret * base;
		base = base * base, t >>= 1;
	}
	return ret;
}

signed main ()
{
	/*
	power[0] = 1ul;
	for (Re int i = 1; i <= 1000000; ++ i)
		power[i] = power[i-1] * base;
	*/
	register ull hasha;
	register int ans, i, top;
	register int _, n, m; //scanf ("%d", &_);
	//while (_ --)
	//{
		scanf ("%s %s", a+1, b+1); n=strlen(a+1), m=strlen(b+1);
		//top = n>m?n:m;
		//power[0] = 1ul;
		//for (i = 1; i <= top; ++ i)
			//power[i] = power[i-1] * base;
		top=n-m, hasha=0ul, hash[0]=0ul;
		//printf ("top %d\n", top);
		for (i = 1; i <= m; ++ i)
			hasha=hasha*base+((b[i]^'a')+1);
		for (i = 1; i <= n; ++ i)
			hash[i]=hash[i-1]*base+((a[i]^'a')+1);
		ans = 0;
		register ull power = qpow (131ul, m);
		for (i = 0; i <= top; ++ i)
			if (hasha==hash[i+m]-hash[i]*power) ++ ans;
		printf ("%d\n", ans);
	//}
	return 0;
}
