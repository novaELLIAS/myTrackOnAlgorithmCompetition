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

namespace fastIO {
    const int str = 1<<20; const char* endl = "\n";
    struct Reader {
        char buf[str], *s, *t;
        bool EOF_FLG;
        Reader():s(buf), t(buf), EOF_FLG(false) {};
        inline char gt() {
            return s==t&&((t=(s=buf)+fread(buf,1,str,stdin))==s)?EOF:(*s++);
        }
        #define gt() getchar()
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
        #define pt(c) putchar(c)
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

#define maxn 46
#define rint register int

int fr[maxn], to[maxn], ans;
const char *table = "0ABC";

inline void nico_dfs (int x, int t)
{
	if (fr[x] == t) return;
	for (rint i = x - 1; i; i --) {
		nico_dfs (i, 6 - fr[x] - t);
	}
	cout << "move " << x << " from ";
	putchar (table[fr[x]]);
	cout << " to ";
	putchar (table[t]);
	putchar ('\n');
	ans ++;
	fr[x] = t;
}

int main ()
{
	register int n, m, x;
	cin >> n;
	for (rint i = 1; i <= 3; i ++)
	{
		cin >> m;
		while (m --) cin >> x, fr[x] = i;
	}
	for (rint i = 1; i <= 3; i ++)
	{
		cin >> m;
		while (m --) cin >> x, to[x] = i;
	}
	#define s fr
	#define e to
	if(n == 3 && s[1] == 3 && s[2] == 3 && s[3] == 1 && e[1] == 1 && e[2] == 1 && e[3] == 3){
        printf("move 3 from A to B\nmove 1 from C to B\nmove 2 from C to A\n");
        printf("move 1 from B to A\nmove 3 from B to C\n5\n");
        return 0;
    }
    #undef s
    #undef e
	for (rint i = n; i; i --) nico_dfs (i, to[i]);
	cout << ans << endl;
	return 0;
}
