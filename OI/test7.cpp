//It is made by jump~
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
#include <set>
#ifdef WIN32   
#define OT "%I64d"
#else
#define OT "%lld"
#endif
using namespace std;
typedef long long LL;
const int MAXC = 1011;
int daan;
/*
       0     1
       2     3
4  5   6     7  8  9 10
      11    12
13 14 15 16 17 18 19
      20    21
      22    23  */
int mp[12][12]={{0,2,6,11,15,20,22}/*A*/,{1,3,8,12,17,21,23}/*B*/,{10,9,8,7,6,5,4}/*C*/,{19,18,17,16,15,14,13}/*D*/};
int fan[12] = {5,4,7,6,1,0,3,2};
int zhong[12] = {6,7,8,11,12,15,16,17};//ÖÐÐÄµÄ±àºÅ
int a[45];

inline int getint()
{
    int w=0,q=0;
    char c=getchar();
    while((c<'0' || c>'9') && c!='-') c=getchar();
    if (c=='-')  q=1, c=getchar();
    while (c>='0' && c<='9') w=w*10+c-'0', c=getchar();
    return q ? -w : w;
}

inline bool already() {
    for(int i=0;i<=7;i++) if (a[zhong[i]]!=a[zhong[0]]) return false;
    return true;
}

inline int coun(int check) {
    int jishu=0;
    for(int i=0;i<8;i++)  if(a[zhong[i]]!=check) jishu++;
    return jishu;
}

inline int gu() {
    int ljh=coun(1);
    for(int i=2;i<=3;i++)
    ljh=min(coun(i),ljh);
    return ljh;
}

inline void move(int x) {
    int cun=a[mp[x][0]];
    for(int i=0;i<6;i++) a[mp[x][i]]=a[mp[x][i+1]];
    a[mp[x][6]]=cun;
}

inline bool dfs(int d,int maxd,int last) {
    if(already()) return true;

    if(d+gu()>maxd) return false;

    for(int i=0;i<8;i++) {
    if(last==fan[i]) continue;
    move(i);
    if(dfs(d+1,maxd,i)) return true;
    move(fan[i]);
    }

    return false;
}

inline void init(){
    fan[10]=-1;
    for(int i=4;i<=7;i++) 
    for(int j=0;j<=6;j++) 
        mp[i][j]=mp[fan[i]][6-j];
}

inline void solve(){
    init();
    int xx;
    while(scanf("%d",&xx)!=EOF && xx) {
    a[0]=xx; for(int i=1;i<=23;i++) scanf("%d",&a[i]);
    if(already())  printf("0\n");       
        else {
        daan=1;
        for(;;daan++)
        if(dfs(0,daan,10))  break;
    }
    printf("%d\n",daan);
    }
}

int main()
{
    solve();
    return 0;
}
