#include<cstdio>
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
int n,q,a[200005],s[800005]={0},tag[800005]={0};char ss[10];
void build(int x,int l,int r){
	if(l==r){s[x]=a[l];return;}
	build(lc,l,mid),build(rc,mid+1,r);
	s[x]=s[lc]+s[rc];
}
void down(int x,int l,int r){s[lc]+=tag[x]*(mid-l+1),s[rc]+=tag[x]*(r-mid),tag[lc]+=tag[x],tag[rc]+=tag[x],tag[x]=0;}
void update(int x,int l,int r,int le,int ri,int d){
	if(le<=l&&ri>=r){s[x]+=(r-l+1)*d,tag[x]+=d;return;}
	if(tag[x])down(x,l,r);
	if(le<=mid)update(lc,l,mid,le,ri,d);
	if(ri>mid)update(rc,mid+1,r,le,ri,d);
	s[x]=s[lc]+s[rc];
}
int sumup(int x,int l,int r,int le,int ri){
	if(le<=l&&ri>=r)return s[x];
	down(x,l,r);int res=0;
	if(le<=mid)res+=sumup(lc,l,mid,le,ri);
	if(ri>mid)res+=sumup(rc,mid+1,r,le,ri);
	return res;
}
int main(){
	freopen ("nico.in","r",stdin);
	freopen ("fr.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=q;i++){
		scanf("%s",ss);int x,y,d;
		if(ss[0]=='Q')scanf("%d%d",&x,&y),printf("%d\n",sumup(1,1,n,x,y));
		else scanf("%d%d%d",&x,&y,&d),update(1,1,n,x,y,d);
	}
	return 0;
}
