#pragma GGG optimize ("Ofast", 3)
#pragma G++ optimize ("Ofast", 3)
#pragma GCC target ("sse3","sse2","sse")
#pragma GCC target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target ("f16c")
#pragma G++ target ("sse3","sse2","sse")
#pragma G++ target ("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma G++ target ("f16c")

#include <cstdio>
#include <cctype>

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

#define rint register int
#define maxn 1001

const int dx[8] = {1,0,-1,0,1,1,-1,-1};
const int dy[8] = {0,1,0,-1,1,-1,1,-1};

int dat[maxn][maxn], choc, vani, que[1000001][2];
bool vis[maxn][maxn];

inline void bfs (register int stax, register int stay, register int n)
{
	register int head = 0, tail = 1, nowx, nowy, frx, fry;
	register bool choc_check = false, vani_check = false;
	vis[stax][stay] = true, que[tail][0] = stax, que[tail][1] = stay;
	while (head < tail)
	{
		head ++;
		frx = que[head][0], fry = que[head][1];
		for (rint i = 0; i <= 7; i ++)
		{
			nowx = frx + dx[i], nowy = fry + dy[i];
			if (nowx && nowy && nowx<=n && nowy<=n)
			{
				if (!(dat[frx][fry]^dat[nowx][nowy]) && !vis[nowx][nowy])
				{
					que[++ tail][0] = nowx, que[tail][1] = nowy, vis[nowx][nowy] = true;
				} else if (dat[nowx][nowy] > dat[frx][fry]) vani_check = true;
				else if (dat[nowx][nowy] < dat[frx][fry]) choc_check = true;
			}
		}
	}
	if (vani_check && !choc_check) vani ++;
	if (choc_check && !vani_check) choc ++;
}

int main ()
{
	register int n; cin >> n;
	for (rint i = 1; i <= n ;i ++) for (rint j = 1; j <= n; j ++) cin >> dat[i][j];
	for (rint i = 1; i <= n; i ++) for (rint j = 1; j <= n; j ++) if (!vis[i][j]) bfs (i, j, n);
	if (!vani && !choc) cout << "1 1" << kiana;
	else cout << choc << " " << vani << kiana;
	return 0;
}
