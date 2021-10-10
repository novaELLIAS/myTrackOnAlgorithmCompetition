
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#define EPS 1e-9
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define LL long long
const int MOD = 1E9+7;
const int N = 100000+5;
const int dx[] = {-1,1,0,0,-1,-1,1,1};
const int dy[] = {0,0,-1,1,-1,1,-1,1};
using namespace std;
int a[N],b[N];
int cmp(int a,int b){
    return a>b;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
 
    //最小值
    sort(a+1,a+1+n,cmp);
    for(int i=2;i<=n;i++)
        a[i]=a[i]*a[i-1]+1;
    int minn=a[n];
    //最大值
    sort(b+1,b+1+n);
    for(int i=2;i<=n;i++){
        b[i]=b[i]*b[i-1]+1;
        sort(b+1,b+n+1);
    }
    int maxx=b[n];
 
    printf("%d\n",maxx-minn);
 
    return 0;
}
