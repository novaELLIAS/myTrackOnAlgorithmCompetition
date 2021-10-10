#pragma G++ optimize ("Ofast", 3)
#pragma GCC optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <cctype>
#include <algorithm>

namespace fastIO {
    const int str=1<<20;
    const char* endll="\n";
    struct Reader {
        char buf[str],*s,*t;
        bool EOF_FLG;
        Reader():s(buf),t(buf),EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
        template<typename T>Reader&operator>>(T&x) {
            if(EOF_FLG)return *this;
            register char c=0,d;
            while(c!=EOF&&!isdigit(c))d=c,c=gt();
            if(c==EOF) {
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

#define maxn 66
#define rint register int

int n, cnt, sum, a[maxn], next[maxn], len, tot;
bool vis[maxn], flag;

inline bool cmp (int aa, int bb) {return aa > bb;}

inline void nico_dfs (int pos, int las, int res)
{
	if (!res)
	{
		if (pos == tot) {flag = true;return;}
		register int x = 1;
		for (; x <= cnt && vis[x]; x ++);
		vis[x] = true;
		nico_dfs (pos+1, x, len - a[x]);
		vis[x] = false;
		if (flag) return;
	}
	register int l = las + 1, r = cnt, mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (a[mid] <= res) r = mid;
		else l = mid + 1;
	}
	
	for (rint i = l; i <= cnt ; i ++)
	{
		if (!vis[i])
		{
			vis[i] = true;
			nico_dfs (pos, i, res - a[i]);
			vis[i] = false;
			if (flag) return;
			if (res == a[i] || res == len) return;
			i = next[i];
			if (i == cnt) return;
		}
	}
}

int main ()
{
	fastIO::cin >> n;
	register int d;
	for (rint i = 1; i <= n; i ++)
	{
		fastIO::cin >> d;
		if (d <= 50) a[++ cnt] = d, sum += d;
	}
	std::sort (a+1, a+cnt+1, cmp);
	next[cnt] = cnt;
	for (rint i = cnt - 1; i; i --)
	{
		next[i] = a[i]==a[i+1]? next[i+1]:i;
	}
	d = sum >> 1, vis[1] = true;
	for (len = a[1]; len <= d; len ++)
	{
		if (!(sum%len)) {
			tot = sum / len;
			nico_dfs (1, 1, len - a[1]);
			if (flag) {
				cout << len;
				return 0;
			} 
		}
	}
	fastIO::cout << sum;
	return 0;
}
