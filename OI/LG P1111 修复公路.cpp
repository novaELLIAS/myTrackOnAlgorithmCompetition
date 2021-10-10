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

namespace fastIO {
    const int str = 1<<20; const char* endl = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
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

#define maxn 1001
#define maxm 100001
#define rint register int

struct node {
	int fr, to, val;
	bool operator < (const node x) {
		return val < x.val;
	}
} a[maxm];
int fa[maxn];

inline int find (int x)
{
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

inline const int& max (const int& aa, const int& bb) {return aa>bb? aa:bb;}

int main ()
{
	register int n, m, sum = 0, ans = -1, x, y; cin >> n >> m;
	for (rint i = 1; i <= n; i ++) fa[i] = i;
	for (rint i = 1; i <= m; i ++) cin >> a[i].fr >> a[i].to >> a[i].val;
	std::sort (a+1, a+m+1);
	for (rint i = 1; i <= m; i ++)
	{
		x = find(a[i].fr), y = find (a[i].to);
		if (x != y) {
			fa[x] = y, ans = max (a[i].val, ans), sum ++;;
		}
	}
	if (sum >= n-1) cout << ans;
	else cout << "-1";
	return 0;
}
