#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <stdio.h>
#include <ctype.h>
#include <algorithm>

#define rint register int
#define maxn 21
#define maxa 101
#define maxm 2001

namespace fastIO {
    const int str = 1<<20; const char* endl = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
    	}
    	//#define gt() getchar ()
        template <typename T> Reader&operator >> (T&x) {
            if (EOF_FLG)return *this;
            register char c=0,d;
            while (c != EOF && (!isdigit(c)))d=c,c=gt();
            if(c == EOF) {
                EOF_FLG=true;
                return *this;
            } else x=0;
            while(isdigit(c))x=(x<<3)+(x<<1)+c-'0',c=gt();
            if(d=='-')x=-x;
            return *this;
        }
    } cin;
    struct Writer {
        char buf[str],*s,*t;
        Writer():s(buf),t(buf+str) {}
        ~Writer() {
            fwrite(buf,1,s-buf,stdout);
        }
        inline void pt(char c) {
            (s==t)?(fwrite(s=buf,1,str,stdout),*s++=c):(*s++=c);
        }
        //#define pt(c) putchar (c)
        template<typename T>Writer&operator<<(T x) {
            if(!x)return pt('0'),*this;
            if(x<0)pt('-'),x=-x;
            register char a[30],t=0;
            while(x)a[t++]=x%10,x/=10;
            while(t--)pt(a[t]+'0');
            return *this;
        }
        Writer&operator<<(const char*s) {
            while(*s)pt(*s++);
            return *this;
        }
    } cout;
}

using namespace fastIO;

inline const int& max (const int& x,const int& y) {return x>y? x:y;}

int n, m, ans = -1, maxx;
int a[maxn];
bool vis[maxn], dp[maxm];

inline void nico_dp ()
{
	for (rint i = 1; i <= maxx; i ++) dp[i] = false;
	dp[0] = true;
	register int ret = 0;
	for (rint i = 0; i < n; i ++)
	{
		if (vis[i]) continue;
		for (rint j = maxx; j >= a[i]; j --)
		{
			if (dp[j-a[i]] && !dp[j]) ret ++, dp[j] = true;
		}
	}
	ans = max (ans, ret);
}

inline void nico_dfs (int pos, int now)
{
	if (now > m) return;
	if (pos == n) {
		if (now == m) nico_dp ();
		return;
	}
	nico_dfs (pos + 1, now);
	vis[pos] = true;
	nico_dfs (pos + 1, now + 1);
	vis[pos] = false;
}

int main ()
{
	cin >> n >> m;
	for (rint i = 0; i < n; i ++) cin >> a[i], maxx += a[i];
	std::sort (a, a+n);
	nico_dfs (0, 0);
	cout << ans;
	return 0;
}
