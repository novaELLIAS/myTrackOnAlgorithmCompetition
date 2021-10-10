#define IO(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#include<cstdio>
#include<iostream>
#include<queue>
#define Re register
using namespace std;
const int N=101;
int a,b,c,n,ans=0x7fffffff;
int d[N][N][N],M1[N][N][N],m1[N][N][N],M2[N][N][N],m2[N][N][N];
deque<int> Q,q;
inline int read() {
    char c=0,d;
    int r=0;
    do d=c,c=getchar();
    while(c<'0'||c>'9');
    do r=(r<<1)+(r<<3)+c-'0',c=getchar();
    while(c>='0'&&c<='9');
    if(d=='-')r=-r;
    return r;
}
inline void wt(int x) {
    if(x/10)wt(x/10);
    putchar('0'+x%10);
}
inline void writeln(int x) {
    if(x<0)putchar('-'),x=-x;
    wt(x),putchar('\n');
}
int main() {
    //IO("cube");
    a=read(),b=read(),c=read(),n=read();
    for(int i=0; i<a; ++i)
        for(int j=0; j<b; ++j)
            for(int k=0; k<c; ++k)
                d[i][j][k]=read();
                puts ("---");
    for(int i=0; i<a; ++i)
        for(int j=0; j<b; ++j) {
            Q.clear(),q.clear();
            for(int k=0; k<n-1; ++k) {
                while((!Q.empty())&&d[i][j][Q.back()]<d[i][j][k])Q.pop_back();
                Q.push_back(k);
                while((!q.empty())&&d[i][j][q.back()]>d[i][j][k])q.pop_back();
                q.push_back(k);
            }
            for(int k=n-1; k<c; ++k) {
                while((!Q.empty())&&Q.front()<k-n+1)Q.pop_front();
                while((!Q.empty())&&d[i][j][Q.back()]<d[i][j][k])Q.pop_back();
                Q.push_back(k);
                M1[i][j][k-n+1]=d[i][j][Q.front()];
                while((!q.empty())&&q.front()<k-n+1)q.pop_front();
                while((!q.empty())&&d[i][j][q.back()]>d[i][j][k])q.pop_back();
                q.push_back(k);
                m1[i][j][k-n+1]=d[i][j][q.front()];
            }
        }
        
        for (Re int i = 0; i < a; ++ i)
	{
		for (Re int j = 0; j < b; ++ j)
		{
			for (Re int k = 0; k < c; ++ k) printf ("%d ", M1[i][j][k]);
			puts ("");
		}
	}puts ("---");
	for (Re int i = 0; i < a; ++ i)
	{
		for (Re int j = 0; j < b; ++ j)
		{
			for (Re int k = 0; k < c; ++ k) printf ("%d ", m1[i][j][k]);
			puts ("");
		}
	}puts ("---");
        
        
    for(int i=0; i<a; ++i)
        for(int k=0; k<c-n+1; ++k) {
            Q.clear(),q.clear();
            for(int j=0; j<n-1; ++j) {
                while((!Q.empty())&&M1[i][Q.back()][k]<M1[i][j][k])Q.pop_back();
                Q.push_back(j);
                while((!q.empty())&&m1[i][q.back()][k]>m1[i][j][k])q.pop_back();
                q.push_back(j);
            }
            for(int j=n-1; j<b; ++j) {
                while((!Q.empty())&&Q.front()<j-n+1)Q.pop_front();
                while((!Q.empty())&&M1[i][Q.back()][k]<M1[i][j][k])Q.pop_back();
                Q.push_back(j);
                M2[i][j-n+1][k]=M1[i][Q.front()][k];
                while((!q.empty())&&q.front()<j-n+1)q.pop_front();
                while((!q.empty())&&m1[i][q.back()][k]>m1[i][j][k])q.pop_back();
                q.push_back(j);
                m2[i][j-n+1][k]=m1[i][q.front()][k];
            }
        }
        
             for (Re int i = 0; i < a; ++ i)
	{
		for (Re int j = 0; j < b; ++ j)
		{
			for (Re int k = 0; k < c; ++ k) printf ("%d ", M2[i][j][k]);
			puts ("");
		}
	}puts ("---");
	for (Re int i = 0; i < a; ++ i)
	{
		for (Re int j = 0; j < b; ++ j)
		{
			for (Re int k = 0; k < c; ++ k) printf ("%d ", m2[i][j][k]);
			puts ("");
		}
	}puts ("---");
        
    for(int k=0; k<c-n+1; ++k)
        for(int j=0; j<b-n+1; ++j) {
            Q.clear(),q.clear();
            for(int i=0; i<n-1; ++i) {
                while((!Q.empty())&&M2[Q.back()][j][k]<M2[i][j][k])Q.pop_back();
                Q.push_back(i);
                while((!q.empty())&&m2[q.back()][j][k]>m2[i][j][k])q.pop_back();
                q.push_back(i);
            }
            for(int i=n-1; i<a; ++i) {
                while((!Q.empty())&&Q.front()<i-n+1)Q.pop_front();
                while((!Q.empty())&&M2[Q.back()][j][k]<M2[i][j][k])Q.pop_back();
                Q.push_back(i);
                while((!q.empty())&&q.front()<i-n+1)q.pop_front();
                while((!q.empty())&&m2[q.back()][j][k]>m2[i][j][k])q.pop_back();
                q.push_back(i);
                ans=min(ans,M2[Q.front()][j][k]-m2[q.front()][j][k]);
            }
        }
    writeln(ans);
}
