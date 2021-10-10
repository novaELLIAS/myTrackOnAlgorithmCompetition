#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include <stack>

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
using namespace std;

#define maxn 1001
#define rint register int

int fa[maxn], de[maxn];
bool vis[maxn];
vector <int> e[maxn];
queue <int> que;
stack <int> sta;

inline void nico (int x, int deep)
{
	if (deep > 2) return;
	vis[x] = true;
	for (rint i = e[x].size()-1; i >= 0; i --) {
		nico (e[x][i], deep+1);
	}
}

int main ()
{
	register int n, ans = 0; cin >> n;
	for (rint i = 2; i <= n; i ++)
	{
		cin >> fa[i];
		e[fa[i]].push_back(i), e[i].push_back(fa[i]);
	}
	que.push (1), sta.push (1), de[1] = 1;
	register int fro, to;
	while (!que.empty()) {
		fro = que.front(), que.pop();
		for (rint i = e[fro].size()-1; i >= 0; i --)
		{
			to = e[fro][i];
			if (to == fa[fro]) continue;
			de[to] = de[fro] + 1;
			que.push(to), sta.push(to); 
		}
	}
	while (!sta.empty()) {
		fro = sta.top(), sta.pop();
		if (!vis[fro]) {
			++ ans, nico (fa[fa[fro]], 0);
		}
	}
	cout << ans;
	return 0;
}
