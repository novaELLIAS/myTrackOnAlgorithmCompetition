#define IO(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;
const int N=(int)1e7,M=(int)1e6,Mod=(int)1e9+7;
int n,m,y,x,l,r;
int prm[M],cnt;
int sum[N+10];
char vis[N+10];
const int ELAS = 1<<14;
static char buf[ELAS],*p1=buf,*p2=buf;
inline char gc()
{
	return (p1==p2)&&(p2=(p1=buf)+fread(buf,1,ELAS,stdin),p1==p2)?EOF:*p1++;
}
inline int read(){
    register char c=gc(),d=0;
    while(c<'0'||c>'9')d=c,c=gc();
    register int r=0;
    while(c>='0'&&c<='9')r=(r<<1)+(r<<3)+c-'0',c=gc();
    return d=='-'?-r:r;
}
inline void wt(ll x){
    if(x/10)wt(x/10);
    putchar(x%10+'0');
}
inline void wtln(ll x){
    if(x<0)putchar('-'),x=-x;
    wt(x),putchar('\n');
}
int main(){
    IO("prime");
    n=read(),m=read();
    for(int i=2;i<=N;++i){
        if(!vis[i])prm[cnt++]=i;
        for(int j=0;i*prm[j]<=N&&j<cnt;++j){
            vis[i*prm[j]]=1;
            if(i%prm[j]==0)break;
        }
    }
    for(int i=0;i<n;++i){
        y=x=read();
        if(y==0)continue;
        for(int j=0;j<cnt;++j){
            if(y%prm[j]==0){
                ++sum[prm[j]];
                while(y%prm[j]==0)y/=prm[j];
            }
            if(vis[y]==0){
                ++sum[y];
                break;
            }
        }
    }
    sum[1]=0;
    for(int i=1;i<=N;++i)sum[i]=(sum[i]+sum[i-1])%Mod;
    for(int i=0;i<m;++i){
        l=read(),r=read();
        wtln((sum[r]-sum[l-1]+Mod)%Mod);
    }
}
