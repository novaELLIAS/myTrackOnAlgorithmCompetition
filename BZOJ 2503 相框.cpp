#pragma G++ optimize ("Ofast", 3)

#include <cstdio>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc();
	while (c < '0' || c > '9') c = gc ();
	while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
	return x;
}

#define Re register
#define maxn 101010

int fa[maxn], de[maxn];
bool vis1[maxn], vis2[maxn];

inline int find (register int x)
{
	while (x ^ fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

int main ()
{
	register int n = read (), m = read ();
	register int fr, to, ffr, fto, top = (m << 1) + n;
	for (Re int i = 1; i <= top; ++ i) fa[i] = i;
	while (m --)
	{
		fr = read (), to = read ();
		if (!fr) fr = ++ n; ++ de[fr], ffr = find(fr);
		if (!to) to = ++ n; ++ de[to], fto = find(to);
		if (ffr ^ fto) fa[ffr] = fto;
	}
	register int ans = 0, tmp = 0, psi = 0;
	for (Re int i = 1; i <= n; ++ i)
	{
		if (de[i])
		{
			fr = find(i);
			if (fr  ==  i) ++ psi;
			if (de[i] > 2) ++ ans, vis2[fr] = true;
			if (de[i] & 1) ++ tmp, vis1[fr] = true;
		}
	}
	//printf ("%d\n", psi);
	if (psi > 1)
		for (Re int i = 1; i <= n; ++ i)
			if (de[i] && i == find(i) && !vis1[i]) {
				tmp += 2;
				if (!vis2[i]) ++ ans;
			}
	printf ("%d", ans + (tmp >> 1));
	return 0;
}
