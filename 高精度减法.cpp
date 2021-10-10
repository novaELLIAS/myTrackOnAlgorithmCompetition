#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAXN=1000001;

int a[MAXN],b[MAXN],c[MAXN];
string a1,b1,temp;
int lena, lenb, lenc;
int i;

int main() {
	cin>>a1>>b1;
	lena=a1.length();
	lenb=b1.length();
	if (lena<lenb or lena==lenb and a1<b1) {
		temp=a1;
		a1=b1;
		b1=temp;
		printf("-");
	}
	for(int i=0;i<lena;i++) a[i]=a1[lena-i-1]-'0';
	for(int i=0;i<lenb;i++) b[i]=b1[lenb-i-1]-'0';
	while(lenc<=lena or lenc<=lenb) {
		if (a[lenc]<b[lenc]) {
			a[lenc]+=10;
			a[lenc+1]--;
		}
		a[lenc]-=b[lenc];
		lenc++;
	}
	while(a[lenc]==0 and lenc>0) lenc--;
	for(int i=lenc;i>=0;i--) printf("%d",a[i]);
	return 0;
}
