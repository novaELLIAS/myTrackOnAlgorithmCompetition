#include<cstdio>
#include<algorithm>
using namespace std;
int g[1501][1501],du[1501],cu[1501];//һ��ʼ���鿪500WA�����һ��
int n,e,ctp,i,j,x,y,st=1,m,mi,p;
void f(int i) {
	for(int j=mi; j<=m; ++j)
		if(g[i][j]) {
			g[i][j]--;
			g[j][i]--;//Ҫ�����ģ���������֮��ܶ����ߣ�
			f(j);
		}
	cu[++ctp]=i;
}
//ŷ����·����
int main() {
	scanf("%d",&e);
	for(i=1; i<=e; ++i) {
		scanf("%d%d",&x,&y);
		++g[y][x];
		++g[x][y];
		du[x]++;
		du[y]++;//ŷ����·��ͳ�ƻ���
		m=max(m,x);
		m=max(m,y);
		mi=min(mi,x);
		mi=min(mi,y);
	}
	printf("\nmi\n%d\n",mi);
//�������ݲ���1��ʼ��ͳ����������СQAQ����ò��ֻ��Ҫͳ�����ֵ�ͺ���
	for(i=mi; i<=m; ++i)
		if(du[i]%2) {
			st=i;
			break;
		}
//�ҵ���С����������ѭ������ʼ����
	f(st);
	for(i=ctp; i>=1; --i) //�ǵ÷������
		printf("%d\n",cu[i]);
	return 0;
}
