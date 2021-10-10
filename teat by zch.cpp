#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int MX=50001;
int n,m,block,c[MX],pos[MX],L,R,sum[MX];long long ans,temp,len;
struct node{
    int l,r,num;long long a,b;
}q[MX];

long long gcd(long long a,long long b)
{
    if(a%b==0)	return b;
    else		return gcd(b%a,a);
}
bool cmp_1(node &a,node &b)
{
    return (pos[a.l]==pos[b.l])?a.r<b.r:a.l<b.l;
}
bool cmp_2(node &a,node &b)
{
    return a.num<b.num;
}
void update(int x,int oper)
{
    ans=ans-sum[c[x]]*sum[c[x]];
    sum[c[x]]+=oper;
    ans=ans+sum[c[x]]*sum[c[x]];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)	scanf("%d",&c[i]);
    for(int i=1;i<=m;i++)	scanf("%d%d",&q[i].l,&q[i].r);
    for(int i=1;i<=m;i++)	q[i].num=i;//记录提问的顺序 
    block=sqrt(n);//计算块的大小 
    for(int i=1;i<=n;i++)	pos[i]=(i-1)/block+1;//计算出每个位置所属的块 
    sort(q+1,q+m+1,cmp_1);//按处理顺序排序 
    sum[c[1]]=ans=L=R=1;
    for(int i=1;i<=m;i++)
    {
        if(q[i].l==q[i].r)	{q[i].b=1;continue;}
        while(L<q[i].l)		{update(L ,-1);L++;}
        while(L>q[i].l)		{update(L-1,1);L--;}
        while(R>q[i].r)		{update(R ,-1);R--;}
        while(R<q[i].r)		{update(R+1,1);R++;}
        len=q[i].r-q[i].l+1;
        q[i].a=ans-len,q[i].b=len*(len-1);
        temp=gcd(q[i].a,q[i].b);
        if(temp!=1)	q[i].a/=temp,q[i].b/=temp;
    }
    sort(q+1,q+m+1,cmp_2);//按提问顺序排序
    for(int i=1;i<=m;i++)	printf("%d/%d\n",q[i].a,q[i].b);
    return 0; 
}
