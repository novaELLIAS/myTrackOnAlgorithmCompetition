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

struct node {
	int sta, end, val;
} a[30001];
bool vis[30001];
int c[30001];

inline void add (int x, int n) {for(; x <= n; x += x&-x) ++ c[x];}
inline int sum (int x) {rint ret = 0; for (; x; x -= x&-x) ret += c[x]; return ret;}
inline bool cmp (node aa, node bb) {return aa.end < bb.end;}

int main ()
{
	register int n, m, x, y, res;
	cin >> n >> m;
	for (rint i = 1; i <= m; i ++) cin >> a[i].sta >> a[i].end >> a[i].val;
	std::sort (a+1, a+m+1, cmp);
	register int ans = 0, t;
	for (rint i = 1; i <= m; i ++)
	{
		x = sum (a[i].sta - 1), y = sum (a[i].end), res = a[i].val + x - y;
		if (res <= 0) continue;
		for (rint j = a[i].end; j >= a[i].sta; j --)
		{
			if (!vis[j]) {
				vis[j] = true, ans ++, add (j, n);
				if (!(-- res)) break;
			}
		}
	}
	cout << ans;
	return 0;
}
