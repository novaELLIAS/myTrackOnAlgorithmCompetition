#pragma G++ optimize (3)

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
    while ((c < '0' || c > '9')) c = gc();
    while (c>='0'&&c<='9') x = (x<<3) + (x<<1) + (c^'0'), c = gc();
    return x;
}

typedef long long ll;
#define Re register
#define maxn 2000005
static char s[maxn];
const long long base = 131;
long long hash[maxn], updg[maxn];

inline void work ()
{
	register int n = read (), pos;
	if (!(n%2)) return (void) printf ("NOT POSSIBLE\n");
	register int pos1 = n >> 1, pos2 = (n >> 1) + 1;
	register long long s1 = 0ll, s2 = 0ll, prefix;
	register bool flag = false;
	register char c = gc(); updg[0] = 1ll;
	while (c == '\n' || c == '\r') c = gc ();
	for (Re int i = 1; i <= n; ++ i)
		hash[i] = hash[i-1]*base+1ll*c, updg[i] = updg[i-1]*base, s[i] = c, c = gc ();
	for (Re int i = 1; i <= n; ++ i)
	{
		s1 = i>pos1? hash[pos1]:(hash[pos2] - hash[i] * updg[pos2-i] + hash[i-1] * updg[pos2-i]);
		s2 = i>pos2? (hash[n]-hash[i]*updg[n-i]+updg[n-i]*(hash[i-1]-hash[pos1]*updg[i-pos2])):(hash[n]-hash[pos2]*updg[pos1]);
		//puts ("check1");
		if (s1 == s2)
		{
			//puts ("GET");
			if (flag && s1 ^ prefix) return (void) printf ("NOT UNIQUE\n");
			flag = true, prefix = s1, pos = i;
		}
	}
	if (!flag) return (void) printf ("NOT POSSIBLE\n");
	for (Re int i = 1, cnt = 1; cnt <= pos1; ++ i)
		if (i != pos) putchar (s[i]), ++ cnt;
	putchar ('\n');
}

signed main ()
{
	freopen ("lgg.in", "r", stdin);
	freopen ("lgg.out","w",stdout);
	register int _ = read ();
	while (_ --) work ();
	fclose (stdin), fclose (stdout);
	return 0;
}
