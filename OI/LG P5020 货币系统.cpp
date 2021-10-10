#pragma GCC optimize ("Ofast", 3)

#include <cstdio>
#include <cstring>
#include <algorithm>

const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read ()
{
	register int x = 0; register char c = gc(); register bool m = 0;
	while ((c < '0' || c > '9') && (c ^ '-')) c = gc();
	if (c == '-') c = gc(), m = true;
	while (c>='0'&&c<='9') x = (x << 3) + (x << 1) + (c ^ '0'), c = gc();
	return m? -x:x;
}
static void write (int x)
{
	if (x > 9) write (x / 10);
	putchar (x % 10 + 48);
}
static void writelen (int x) {if(x<0)x=-x,putchar('-'); write (x); putchar ('\n');}

using std::sort;

#define Re register
#define maxn 101

int dat[maxn];
bool vis[25001];

inline const int max (const int& a, const int& b) {return a>b? a:b;}

inline bool cmp (int a, int b) {return a<b;}

inline void work (Re int x, Re int &ans, Re int maxa)
{
    register int i;
    if (vis[dat[x]]) {-- ans; return;}
    vis[dat[x]] = true;
    for (i=dat[x]; i<=maxa; ++i)
        vis[i] |= vis[i-dat[x]];
}

signed main ()
{
    register int T = read ();
    register int i, n, ans, maxa;
    LOOP:while (T --)
    {
        n = ans = read(), maxa=1;
        for (i=1; i<=n; ++i)
        {
            dat[i]=read();
            maxa = max (maxa, dat[i]);
        }
        sort (dat+1, dat+n+1);
        if (dat[1] == 1) {
            printf ("1\n"); goto LOOP;
        }
        memset (vis, 0, sizeof vis);
        for (i=1; i<=n; ++i)
        {
            work (i, ans, maxa);
        }
        printf ("%d\n", ans);
    }
    fclose (stdin), fclose (stdout);
    return 0;
}
