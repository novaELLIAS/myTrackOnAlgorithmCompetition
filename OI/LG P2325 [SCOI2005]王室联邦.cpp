#pragma GCC optmize ("Ofast", 3)
#pragma G++ optmize ("Ofast", 3)

#include <cstdio>
#include <cctype>
#include <vector>

using namespace std;

namespace fastIO {
    const int str = 1<<20; const char* kiana = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);}
        template <typename T> Reader&operator >> (T&x)
		{
            if (EOF_FLG)return *this;
            register char c=0,d;
            while (c != EOF && (!isdigit(c)))d=c,c=gt();
            if(c == EOF) {EOF_FLG=true; return *this;} else x = 0;
            while(isdigit(c)) x = (x<<3) + (x<<1) + c - '0', c = gt();
            if (d == '-') x =- x;
            return *this;
        }
    } cin;
    struct Writer {
        char buf[str],*s,*t;
        Writer():s(buf),t(buf+str) {}
        ~Writer() {fwrite(buf,1,s-buf,stdout);}
        inline void pt(char c) {(s==t)?(fwrite(s=buf,1,str,stdout),*s++=c):(*s++=c);}
        template<typename T>Writer&operator<<(T x)
		{
            if(!x) return pt('0'),*this;
            if(x<0) pt('-'), x = -x;
            register char a[30],t=0;
            while(x)a[t++]=x%10,x/=10;
            while(t--)pt(a[t]+'0');
            return *this;
        }
        Writer&operator<<(const char*s) {while(*s)pt(*s++);return *this;}
    } cout;
}

using namespace fastIO;

#define maxn 1001
#define rint register int

vector <int> e[maxn];
int cap[maxn], bel[maxn];
int sta[maxn], top, cnt, b;

static void nico_dfs (register int x, register int fa)
{
	register int now = top, to;
	for (rint i = e[x].size() - 1; i >= 0; i --)
	{
		if ((to = e[x][i]) != fa)
		{
			nico_dfs (to, x);
			if (top - now >= b)
			{
				cap[++ cnt] = x;
				while (top > now) bel[sta[top --]] = cnt;
			}
		}
	}
	sta[++ top] = x;
}

int main ()
{
	register int n; cin >> n >> b;
	if (n < b) {cout << "0" << kiana; return 0;}
	register int fr, to;
	for (rint i = 1; i < n; i ++)
	{
		cin >> fr >> to;
		e[fr].push_back (to), e[to].push_back (fr);
	}
	nico_dfs (1, 0);
	while (top) bel[sta[top --]] = cnt;
	cout << cnt << kiana;
	for (rint i = 1; i <= n; i ++) cout << bel[i] << " ";
	cout << kiana;
	for (rint i = 1; i <= cnt; i ++) cout << cap[i] << " ";
	return 0;
}
