#include<iostream>
#include<cstring>
using namespace std;
const int N=1e4+5,inf=0xfffffff;
struct node {
    int l,r,s,m;
} p[N<<2];
inline node operator +(const node& a,const node& b) {
    node res;
    res.l=max(a.l,a.s+b.l);
    res.r=max(b.r,b.s+a.r);
    res.s=a.s+b.s;
    res.m=max(max(a.m,b.m),a.r+b.l);
    return res;
}
#define Root 1,1,n
#define Lpos pos<<1
#define Rpos pos<<1|1
#define Lson Lpos,l,mid
#define Rson Rpos,mid+1,r
int T,n,q,a[N],x1,x2,y1,y2;
inline void update(int pos) {
    p[pos]=p[Lpos]+p[Rpos];
}
inline void build(int pos,int l,int r) {
    if(l==r) {
        p[pos].l=p[pos].r=p[pos].m=p[pos].s=a[l]-a[l-1];
        return;
    }
    int mid=l+r>>1;
    build(Lson),build(Rson);
    update(pos);
}
static node INF= {-inf,-inf,0,-inf};
inline node query(int pos,int l,int r,int L,int R) {
    if(L>R||r<L||l>R||l>r)return INF;
    if(L<=l&&r<=R)return p[pos];
    int mid=l+r>>1;
    node pl=query(Lson,L,R);
    node pr=query(Rson,L,R);
    return pl+pr;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    while(T--) {
        cin>>n;
        for(int i=1; i<=n; ++i)
            cin>>a[i],a[i]+=a[i-1];
        build(Root);
        cin>>q;
        for(int i=1; i<=q; ++i) {
            cin>>x1>>y1>>x2>>y2;
            if(y1<=x2) {
                node L=query(Root,x1,y1);
                node R=query(Root,x2,y2);
                cout<<L.r+R.l+a[x2-1]-a[y1]<<endl;
            } else {
                node LL=query(Root,x1,x2-1);
                node LR=query(Root,x1,y1);
                node RL=query(Root,x2,y2);
                node RR=query(Root,y1+1,y2);
                node M =query(Root,x2,y1);
                cout<<max(max(LL.r+RL.l,LR.r+RR.l),M.m)<<endl;
            }
        }
    }
}
