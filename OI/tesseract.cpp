#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;

const int inf=0x7fffffff/2;

const int maxn=5010;

int n,s,t,o,A,B,C,cnt,head[maxn],isin[maxn],intime[maxn];

double k,x,l,r=10,mid,dis[maxn];

double min(double a,double b){
    return a<b?a:b;
}

struct Know{
    int pe;
    double dis;
}know[maxn];

struct Edge{
    int f,t,next,kind;
    double k,w;
}edge[maxn];

void addedge(int f,int t,double w,int kind,double k){
    edge[++cnt].t=t;
    edge[cnt].f=f;
    edge[cnt].w=w;
    edge[cnt].kind=kind;
    edge[cnt].k=k;
    edge[cnt].next=head[f];
    head[f]=cnt;
}

bool spfa(double num){
    queue<int>q;
    for(int i=0;i<=n;++i) dis[i]=-inf,intime[i]=0,isin[i]=0;
    q.push(n+1);
    isin[n+1]=1;
    dis[n+1]=0;
    ++intime[n+1];
    while(!q.empty()){
        int fp=q.front();
        q.pop();
        isin[fp]=0;
        for(int i=head[fp];i;i=edge[i].next){
            int tp=edge[i].t;
            double w;
            if(edge[i].kind==0) w=edge[i].w;
            if(edge[i].kind==1) w=log2(edge[i].k-num);
            if(edge[i].kind==2) w=-log2(edge[i].k+num);
            if(dis[tp]<dis[fp]+w){
                dis[tp]=dis[fp]+w;
                if(!isin[tp]){
                    q.push(tp);
                    isin[tp]=1;
                    ++intime[tp];
                    if(intime[tp]>=n+1) return false; 
                }
            } 
        }

    }
    return true;
}

int main(){

    scanf("%d%d%d",&n,&s,&t); 

    for(int i=1;i<=s;++i){
        scanf("%d%d%d%lf",&o,&A,&B,&k);
        addedge(B,A,0,o,k);
        if(o==1) r=min(r,k);
    }

    for(int i=1;i<=t;++i){
        scanf("%d%lf",&C,&x);
        addedge(0,C,log2(x),0,0);
        addedge(C,0,-log2(x),0,0);
    }

    for(int i=0;i<=n;++i) addedge(n+1,i,0,0,0);

    if(spfa(0)){
        printf("%d",-1);
        return 0;
    }

    while(r-l>1e-5){
        mid=(r+l)/2;
        if(spfa(mid)) r=mid;
        else l=mid;
    }

    printf("%lf",l);

    return 0;
} 
