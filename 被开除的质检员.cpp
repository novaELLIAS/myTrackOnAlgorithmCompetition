#prag\
ma GCC optimize ("Ofast")

#include "stdio.h"
#include "string.h"

int n,m;

#define maxn 200001
#define rint register int
#define ll long long
#define max(a,b) (a>b? a:b)
#define min(a,b) (a<b? a:b)

int v[maxn], w[maxn], le[maxn], ri[maxn];
ll cntn[maxn], cntv[maxn], s, ans=999999999999999ll, temp;
int maxx = -1, minn = 2147483647;

inline int fastread ()
{
    int sign = 1, n = 0;
    char c = getchar();
    while(c < '0' || c > '9')
    {
        if(c == '-') sign = -1;
        c = getchar();
    }
    while(c >= '0' && c <= '9')
    {
        n = n*10 + c-'0';
        c = getchar();
    }
    return sign*n;
}

inline ll labs(ll a)
{
	return a>0? a:-a;
}

inline bool nico_judge (int x)
{
	memset (cntn, 0, sizeof cntn);
	memset (cntv, 0, sizeof cntv);
	for (rint i = 1; i <= n; i ++)
	{
		if (w[i] >= x)
		{
			cntn[i] = cntn[i-1] + 1;
			cntv[i] = cntv[i-1] + v[i];
		} else {
			cntn[i] = cntn[i-1];
			cntv[i] = cntv[i-1];
		}
	}
	ll cmp = 0LL;
	for (rint i = 1; i <= m; i ++) cmp += (cntn[ri[i]] - cntn[le[i]-1]) * (cntv[ri[i]] - cntv[le[i]-1]);
	temp = labs (s-cmp);
	return cmp>s? true:false;
}

int main() {
	scanf ("%d %d %I64d", &n, &m, &s);
	for (rint i = 1; i <= n; i ++)
	{
		w[i] = fastread ();
		v[i] = fastread ();
		maxx = max (maxx, w[i]);
		minn = min (minn, w[i]);
	}
	
	for (rint i = 1; i <= m; i ++)
	{
		le[i] = fastread ();
		ri[i] = fastread ();
	}
	
	int left = minn-1, right = maxx+2, mid;
	while (left <= right)
	{
		mid = (left+right)>>1;
		if (nico_judge(mid)) left = mid+1;
		else right = mid-1;
		ans = min (ans, temp);
	}
	printf ("%I64d", ans);
	return 0;
}
