#include<bits/stdc++.h>
using namespace std;
int n=10;
int main(){
	freopen("nico.in","w",stdout);
	printf("%d %d\n",n,n);
	for(int i=1;i<=n;++i)printf("%d ",rand()*rand()%1000000+1);
	printf("\n");
	for(int i=1,op,l,r;i<=n;++i){
		op=rand()%2;
		printf("%c ",op?'A':'Q');
		l=rand()*rand()%n+1,r=rand()*rand()%n+1;
		if(l>r)swap(l,r);
		if(op)printf("%d %d %d\n",l,r,rand()*rand()%1000000+1);
		else printf("%d %d\n",l,r);
	}
}
