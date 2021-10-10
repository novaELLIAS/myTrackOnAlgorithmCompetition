#include <stdio.h>
#include <string.h>

const int maxroad=100001;
const int INF=233333333;
int n,road,pos,ans;
int dis_t[1001],dis_b[1001],totdis[1001];
int tow_u[maxroad],tow_v[maxroad],tow_w[maxroad];
int bac_u[maxroad],bac_v[maxroad],bac_w[maxroad];

int READ() {
	int k=0;
	char f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		k=k*10+c-'0';
		c=getchar();
	}
	return k*f;
}
void INPUT() {
	n=READ();
	road=READ();
	pos=READ();
	int x,y,timee;
	for(int i=1; i<=road; i++) {
		x=READ();
		y=READ();
		timee=READ();
		tow_u[i]=bac_v[i]=x;
		tow_v[i]=bac_u[i]=y;
		tow_w[i]=bac_w[i]=timee;
	}
	memset(dis_t,INF,sizeof(dis_t));
	memset(dis_b,INF,sizeof(dis_b));
}
void BELLMAN_FORD_TOW() {
	dis_t[pos]=0;
	int temp=n-1,from,to,via;
	while(temp--) {
		bool judge=false;
		for(int i=1; i<=road; i++) {
			from=tow_u[i],to=tow_v[i],via=tow_w[i];
			if(dis_t[to]>dis_t[from]+via) {
				dis_t[to]=dis_t[from]+via;
				judge=true;
			}
		}
		if(judge==false) break;
	}
	delete tow_u,tow_v,tow_w;
}
void BELLMAN_FORD_BAC() {
	dis_b[pos]=0;
	int temp=n-1,from,to,via;
	while(temp--) {
		bool judge=false;
		for(int i=1; i<=road; i++) {
			from=bac_u[i],to=bac_v[i],via=bac_w[i];
			if(dis_b[to]>dis_b[from]+via) {
				dis_b[to]=dis_b[from]+via;
				judge=true;
			}
		}
		if(judge==false) break;
	}
	delete bac_u,bac_v,bac_w;
}
void FINALCOUNT() {
	for(int i=1; i<=n; i++) totdis[i]=dis_t[i]+dis_b[i];
	delete dis_t,dis_b;
	for(int i=1; i<=n; i++) ans=totdis[i]>ans? totdis[i]:ans;
}
int main(void) {
	INPUT();
	BELLMAN_FORD_TOW();
	BELLMAN_FORD_BAC();
	FINALCOUNT();
	printf("%d",ans);
}
