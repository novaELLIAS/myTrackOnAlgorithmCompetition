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
#include <queue>

using namespace std;

namespace fastIO {
    const int str = 1<<20; const char* endl = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
        //#define gt() getchar()
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
        //#define pt(c) putchar(c)
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

#define rint register int
#define maxn 500001
#define ll long long

long long ans;
int a[maxn], l[maxn], r[maxn];
bool vis[maxn];

struct node {
	int id;
	long long val;
	
	bool operator < (const node& x) const {
		return val < x.val;
	}
};

priority_queue <node> nico;

using namespace fastIO;

int main ()
{
	register int n, k, name, value; cin >> n >> k;
	register node tmp;
	for (rint i = 1; i <= n; i ++) {
		cin >> a[i], tmp.val = a[i], tmp.id = i;
		nico.push (tmp);
		l[i] = i - 1, r[i] = i + 1;
	}
	while (k --)
	{
		while (vis[nico.top().id]) nico.pop ();
		tmp = nico.top (), nico.pop ();
		if (tmp.val < 0) break;
		ans += tmp.val, name = tmp.id, vis[l[name]] = vis[r[name]] = true;
		a[name] = a[l[name]] + a[r[name]] - a[name];
		l[name] = l[l[name]], r[l[name]] = name;
		r[name] = r[r[name]], l[r[name]] = name;
		tmp.val = a[name];
		nico.push (tmp);
	}
	cout << ans;
	return 0;
}
