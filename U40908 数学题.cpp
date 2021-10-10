#define IO(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long ll;

int T;
ll M,I,x,y,z;
ll g12,g23,g13,g123;
ll ans;

inline ll gcd(ll x,ll y) {
    return y?gcd(y,x%y):x;
}

inline ll mul(ll x,ll y) {
    ll res=0;
    while(y) {
        if(y&1)res=(res+x)%M;
        x=(x<<1)%M,y>>=1;
    }
    return res;
}

inline ll read() {
    register char c=0,d;
    register ll r=0;
    do d=c,c=getchar();
    while(c<'0'||c>'9');
    do r=(r<<1)+(r<<3)+c-'0',c=getchar();
    while(c>='0'&&c<='9');
    if(d=='-')r=-r;
    return r;
}
inline void wt(ll x) {
    if(x/10)wt(x/10);
    putchar('0'+x%10);
}
inline void writeln(ll x) {
    if(x<0)putchar('-'),x=-x;
    wt(x),putchar('\n');
}

int main() {

    //IO("math");

    T=read(),M=read();
    
    I=(M+1)>>1;

    for(register int i=1; i<=T; ++i) {

        x=read(),y=read(),z=read();

        g12=gcd(x,y);
        g23=gcd(y,z);
        g13=gcd(x,z);
        g123=gcd(g12,g23);

        ans=mul(x-1,g23)+mul(y-1,g13)+mul(z-1,g12)+x+y+z+g123;

        ans=mul(ans,I);

        ans=(mul(mul(x,y),z)+ans)%M;

        writeln(ans);

    }

}
