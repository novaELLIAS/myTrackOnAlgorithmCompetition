#include<iostream> 
#include<cstdio>
long long read(){
    long long x=0;int f=0;char c=getchar();
    while(c<'0'||c>'9')f|=c=='-',c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return f?-x:x;
}
#define maxn 300001
long long dp[maxn],t[maxn],f[maxn],n,s,q[maxn],l,r;
int main(){
	freopen ("arrangement14.txt", "r", stdin);
    n=read(),s=read();
    for(int i=1;i<=n;i++){
        t[i]=read(),f[i]=read();
        t[i]+=t[i-1],f[i]+=f[i-1];//前缀和
    }
    dp[0]=0,l=1,r=1;
    for(int i=1;i<=n;i++){
        while(l<r&&dp[q[l+1]]-dp[q[l]]<=(s+t[i])*(f[q[l+1]]-f[q[l]])) l++;//更新队头 
        dp[i]=dp[q[l]]+t[i]*f[i]+s*f[n]-f[q[l]]*(s+t[i]);
        while(l<r&&(dp[i]-dp[q[r]])*(f[q[r]]-f[q[r-1]])<=(dp[q[r]]-dp[q[r-1]])*(f[i]-f[q[r]])) r--;//更新队尾 
        q[++r]=i;
    }
    printf("%lld\n",dp[n]);
    return 0;
}
