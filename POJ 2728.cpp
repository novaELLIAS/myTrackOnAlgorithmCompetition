#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

#define For(i,j,n) for(int i=j;i<=n;i++)
#define mst(ss,b) memset(ss,b,sizeof(ss));

typedef  long long LL;

template<class T> void read(T&num) {
	char CH;
	bool F=false;
	for(CH=getchar(); CH<'0'||CH>'9'; F= CH=='-',CH=getchar());
	for(num=0; CH>='0'&&CH<='9'; num=num*10+CH-'0',CH=getchar());
	F && (num=-num);
}
int stk[70], tp;
template<class T> inline void print(T p) {
	if(!p) {
		puts("0");
		return;
	}
	while(p) stk[++ tp] = p%10, p/=10;
	while(tp) putchar(stk[tp--] + '0');
	putchar('\n');
}

const LL mod=1e9+7;
const double PI=acos(-1.0);
const double inf=1e18;
const int N=15e4+10;
const int maxn=1e3+10;
const double eps=1e-5;

int n;
double cost[maxn][maxn],dis[maxn][maxn],x[maxn],y[maxn],z[maxn];
int vis[maxn];

double get_dis(int a,int b) {
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}

int check(double x) {
	mst(vis,0);
	double sum=0,lowcost[maxn];
	vis[1]=1;
	For(i,1,n)lowcost[i]=cost[1][i]-x*dis[1][i];
	For(i,2,n) {
		double temp=inf;
		int k=-1;
		For(j,2,n) {
			if(!vis[j]&&lowcost[j]<temp) {
				k=j;
				temp=lowcost[j];
			}
		}
		if(k==-1)break;
		vis[k]=1;
		sum+=temp;
		For(j,2,n) {
			if(!vis[j]&&cost[k][j]-x*dis[k][j]<lowcost[j])
				lowcost[j]=cost[k][j]-x*dis[k][j];
		}
	}
	if(sum>=0)return 1;
	return 0;
}
int main() {
	while(1) {
		read(n);
		if(n==0)break;
		For(i,1,n) {
			scanf("%lf%lf%lf",&x[i],&y[i],&z[i]);
		}
		For(i,1,n)
		For(j,i+1,n) {
			dis[i][j]=dis[j][i]=get_dis(i,j);
			cost[i][j]=cost[j][i]=abs(z[i]-z[j]);
		}
		double l=0.0,r=100.0;
		while(r-l>=eps) {
			double mid=(l+r)/2;
			if(check(mid))l=mid;
			else r=mid;
		}
		printf("%.3f\n",r);
	}
	return 0;
}
