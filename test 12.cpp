// luogu-judger-enable-o2
#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=110,M=10010;
inline int read() {
    register char c=getchar(),d=0;
    while(c<'0'||c>'9')d=c,c=getchar();
    register int r=0;
    while(c>='0'&&c<='9')r=(r<<1)+(r<<3)+c-'0',c=getchar();
    return d=='-'?-r:r;
}
inline void wt(int x) {
    if(x/10)wt(x/10);
    putchar(x%10+'0');
}
inline void wtln(int x) {
    if(x<0)putchar('-'),x=-x;
    wt(x),putchar('\n');
}
int n,m,a[M];
int ans,d[N][N];
int main() {
    n=read(),m=read();
    for(int i=1;i<=m;++i)
        a[i]=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            d[i][j]=read();
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    for(int i=1;i<m;++i)
        ans+=d[a[i]][a[i+1]];
    wtln(ans);
}
