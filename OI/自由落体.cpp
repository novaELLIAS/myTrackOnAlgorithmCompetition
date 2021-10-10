#include <stdio.h>
#include <math.h>

int main() {
	int n,ans=0;
	double h,s,v,l,k;
	scanf("%lf%lf%lf%lf%lf%d",&h,&s,&v,&l,&k,&n);
	for(double i=0; i<=n-1; i++) {
		if((i-0.0001)<(s-sqrt((h-k)/5)*v+l) && (i+0.0001)>(s-sqrt(h/5)*v)) ans++;
	}
	printf("%d",ans);
}
