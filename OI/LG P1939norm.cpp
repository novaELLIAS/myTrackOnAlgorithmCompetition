#pragma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"

using namespace std;

#define ll long long
#define rint register int
#define modn 1000000007
#define maxn 20000001

inline ll read()
{
	ll x=0ll,t=1ll;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-')t=-1,ch=getchar();
	while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
	return x*t;
}

struct node
{
	ll a[4][4];
} nico, qwq;


ll n, k;


inline node xxx (node aa,node bb)
{
	node ret;
	memset (ret.a, 0, sizeof ret.a);
	for (rint i = 1; i <= 3; i ++)
	{
		for (rint j = 1; j <= 3; j ++)
		{
			for (rint k = 1; k <= 3; k ++)
			{
				ret.a[i][j] += (aa.a[i][k] * bb.a[k][j]) % modn;
				ret.a[i][j] %= modn;
			}
		}
	}
	return ret;
}

node poww (node aa, int k)
{
	if (k <= 1) return aa;
	node ret = aa;
	k --;
	while (k > 0)
	{
		if (k % 2 == 1)
			ret = xxx (ret, aa);
		k /= 2;
		aa = xxx (aa,aa);
	}
	return ret;
}


inline void init ()
{
	nico.a[1][1] = nico.a[3][1] = nico.a[1][2] = nico.a[2][3] = 1ll;
}

int main ()
{
	init ();
	n = read ();
	node kkkk;
	while (n --)
	{
		k = read ();
		printf ("%lld\n",poww (nico, k - 1).a[1][1]);
	}
}
