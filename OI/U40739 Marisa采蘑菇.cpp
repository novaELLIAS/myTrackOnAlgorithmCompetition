

#include <bits/stdc++.h>
using namespace std;

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c<'0'||c>'9') && c != '-') c = gc();
	if (c == '-') c = gc(), m = 1;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {write (x); putchar ('\n');}

#define Re register
#define maxn 1000001

struct node {
	int id, l, r;
} ss[maxn];
inline bool cmp (node a, node b) {return (a.l==b.l)? (a.r<b.r):(a.l<b.l);}
int ans[maxn];
int col[maxn];
int tot[maxn];
int cnt[maxn];
bool flag[maxn];

int main ()
{
	register int n = read (), m = read (), k = read();
	for (Re int i = 1;i<=n;++i) col[i]=read(),++tot[col[i]];
	for(Re int i=1;i<=m;++i) ss[i].id=i,ss[i].l=read(),ss[i].r=read();
	sort(ss+1,ss+m+1,cmp);
	register int l, r, id,ll=0,rr=0;
	for(Re int i=1;i<=m;++i)
	{
		id=ss[i].id,l=ss[i].l,r=ss[i].r;
		while(rr<r)
		{
			rr++;
			++cnt[col[rr]];
			if(abs((cnt[col[rr]]*2)-tot[col[rr]])<=k && !flag[col[rr]]) flag[col[rr]]=true,ans[id]++;
		}
		while(rr>r)
		{
			--cnt[col[rr]];
			if(abs((cnt[col[rr]]*2)-tot[col[rr]]) >k && flag[col[rr]]) flag[col[rr]]=false,ans[id]--;
			rr--;
		}
		while(ll>l)
		{
			ll--;
			++cnt[col[ll]];
			if(abs((cnt[col[ll]]*2)-tot[col[ll]])<=k && !flag[col[ll]]) flag[col[ll]]=true,ans[id]++;
		}
		while(ll<l)
		{
			--cnt[col[ll]];
			if(abs((cnt[col[ll]]*2)-tot[col[ll]]) >k && flag[col[ll]]) flag[col[ll]]=false,ans[id]--;
			ll++;
		}
	}
	for(Re int i=1;i<=m;++i) writelen(ans[i]);
}
