#include <stdio.h>
#include <ctype.h>

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
#define ll long long
#define modn 1000000007
#define maxn 801

int dp[maxn][maxn][20][2], a[maxn][maxn];

using namespace fastIO;

inline int mod (int x, int modd)
{
	if (x<modd) return x;
	return x-modd;
}

int main ()
{
	register int n, m, k, ans = 0;
	cin >> n >> m >> k, k ++;
	for (rint i = 1; i <= n; i ++)
	{
		for (rint j = 1; j <= m; j ++) cin >> a[i][j], dp[i][j][a[i][j]%k][0] = 1;
	}
	for (rint i = 1; i <= n; i ++)
	{
		for (rint j = 1; j <= m; j ++)
		{
			for (rint h = 0; h <= k; h ++)
			{
				dp[i][j][h][0] = mod(dp[i][j][h][0] + dp[i-1][j][mod(h-a[i][j]+k, k)][1], modn);
				dp[i][j][h][0] = mod(dp[i][j][h][0] + dp[i][j-1][mod(h-a[i][j]+k, k)][1], modn);
				dp[i][j][h][1] = mod(dp[i][j][h][1] + dp[i-1][j][mod(h+a[i][j], k)][0], modn);
				dp[i][j][h][1] = mod(dp[i][j][h][1] + dp[i][j-1][mod(h+a[i][j], k)][0], modn);
				if (!h) ans = mod(ans + dp[i][j][0][1], modn);
			}
		}
	}
	cout << ans;
	return 0;
}
