#include <cstdio>
#include <cctype>
#include <cstring>
#include <queue>

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
#define Re register
#define maxn 31
#define maxq 501

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
int n, m, q;
bool use[maxn][maxn], vis[maxn][maxn], visit[maxn][maxn];
bool nico[maxn][maxn][maxn][maxn];
struct node {
    Re int x, y, dis;
};
queue <node> nico;

inline void nico_spfa (int x, int y, int k)
{
    while (!nico.empty()) que.pop ();

}

inv spfa(int x,int y,int k)
{
    queue<o>q;
    d[x][y][x][y][k]=0;
    q.push((o){x,y,0});
    while(!q.empty())
    {
        o t=q.front();
        q.pop();
        see[t.x][t.y]=0;
        for(int i=0;i<4;i++)
          {
              int xxx=t.x+mv1[i],yyy=t.y+mv2[i];
              if(use[xxx][yyy]&&d[x][y][xxx][yyy][k]>d[x][y][t.x][t.y][k]+ll[t.x][t.y][xxx][yyy]&&ll[t.x][t.y][xxx][yyy])
              {
                  d[x][y][xxx][yyy][k]=d[x][y][t.x][t.y][k]+ll[t.x][t.y][xxx][yyy];
                  if(!see[xxx][yyy])
                  {
                      see[xxx][yyy]=1;
                      q.push((o){xxx,yyy,0});
                }
            }
          }
    }
}

int main ()
{
    cin >> n >> m >> q;
    for (Re int i = 1; i <= n; ++ i)
    {
        for (Re int j = 1; j <= m; ++ j) cin >> use[i][j];
    }

    register int tox, toy;
    for (Re int i = 1; i <= n; ++ i)
    {
        for (Re int j = 1; j <= m; ++ j)
        {
            for (Re int k = 0; k <= 3; ++ k)
            {
                tox = i + dx[k], toy = j + dy[k];
                if (use[tox][toy])
                {
                    nico[tox][toy][i][j] = nico[i][j][tox][toy] = true;
                }
            }
        }
    }

    for (Re int i = 1; i <= n; ++ i)
    {
        for (Re int j = 1; j <= m; ++ j)
        {
            for (Re int k = 0; k <= 3; ++ k)
            {
                tox = i + dx[k], toy = j + dy[k];
                if (use[i][j] & ues[tox][toy])
                {
                    use[tox][toy] = false;
                    nico_spfa (i, j, k);
                    use[tox][toy] = true;
                }
            }
        }
    }

    register int tot, s1, s2, e1, e2, t1, t2, minn;
    while (q --)
    {
        tot = 0;
        for (Re int i = 1; i <= n; ++ i)
        {
            for (Re int j = 1; j <= m; ++ j)
            {
                vis[i][j] = use[i][j];
            }
        }
        cin >> e1 >> e2 >> s1 >> s2 >> t1 >> t2;
        if (!(s1^t1) && !(s2^t2)) {cout << "0" << kiana; continue;}
        nico_bfs ();
        if (!tot) {cout << "-1" << continue;}
        minn = 0x3f3f3f3f;
        for (Re int i = 1; i <= tot; ++ i) nico_dfs (s1, s2, en1[i], en2[i], pay[i]);
        if (minn^0x3f3f3f3f) cout << minn << kiana;
        else cout << "-1" << kiana;
    }
    FinalEXIT: return 0;
}
