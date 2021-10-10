#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

map<string,string> nico;

string find(string x) {
	if(x!=nico[x]) nico[x]=find(nico[x]);
	return nico[x];
}
int main() {
	char ch;
	string s,s1;
	ch=getchar();
	while(ch!='$') {
		cin>>s;
		switch(ch){
			case '#':
				s1=s;
				if(nico[s]=="") nico[s]=s;
				break;
			case '+':
				nico[s]=s1;
				break;
			case '?':
				cout<<string(s)<<' '<<string(find(s));
				putchar('\n');
		}
		cin>>ch;
	}
	return 0;
}
