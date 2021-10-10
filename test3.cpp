#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#define LL long long
using namespace std;
int n,m;
int k;
int a,b,wa,wb;
const int maxn=200010;
namespace lian2
{
    inline int read()
    {
        int res=0;char c=getchar();
        while(c<48||c>57)c=getchar();
        while(c>=48&&c<=57)res=(res<<3)+(res<<1)+(c&15),c=getchar();
        return res;
    }
    struct edge
    {
        int to,next;
    }e[maxn<<4];
    int head[maxn],cnt=0;
    int f[maxn][51];
    int rudu[maxn];
    int w[maxn];
    inline void addedge(int u,int v)
    {
        e[++cnt].to=v,e[cnt].next=head[u],head[u]=cnt;
    }
    queue<int>q;
    void del(int x)
    {
        for(int i=head[x];i;i=e[i].next)
        {
            int v=e[i].to;
            rudu[v]--;
            if(!rudu[v]&&v!=1)q.push(v);
        }
    }
    void solve()
    {
        int u,v;
        for(int i=1;i<=n;++i)u=read(),v=read(),w[u]+=v;
        for(int i=1;i<=k;++i)u=read(),v=read(),addedge(u,v),rudu[v]++;
        memset(f,-127,sizeof(f));
        for(int i=2;i<=m;++i)
            if(!rudu[i])q.push(i);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            del(u);
        }
        q.push(1);
        f[1][0]=w[1];
        while(!q.empty())
        {
            int x=q.front();q.pop();
            del(x);
            for(int i=head[x];i;i=e[i].next)
            {
                int v=e[i].to;
                if(f[x][0]!=f[0][0])
                {
                    if(a!=1)f[v][a-1]=max(f[v][a-1],f[x][0]-wa);
                    else f[v][0]=max(f[v][0],f[x][0]-wa+w[v]);
                }
                if(f[x][0]!=f[0][0])
                {
                    if(b!=1)f[v][b-1]=max(f[v][b-1],f[x][0]-wb);
                    else f[v][0]=max(f[v][0],f[x][0]-wb+w[v]);
                }
                if(f[x][1]!=f[0][0])f[v][0]=max(f[v][0],f[x][1]+w[v]);
                for(int j=b;j>1;--j)
                    if(f[x][j]!=f[0][0])f[v][j-1]=max(f[v][j-1],f[x][j]);
            }
        }
        int ans=0;
        for(int i=1;i<=m;++i)ans=max(ans,f[i][0]);
        printf("%d\n",ans);
    }
};
int main()
{
    freopen("faith.in","r",stdin);
    freopen("faith.out","w",stdout);
    scanf("%d%d%d%d%d%d%d",&n,&m,&k,&a,&b,&wa,&wb);
    lian2::solve();
}
