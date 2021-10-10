#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

string w, st;

int main()
{
	ios::sync_with_stdio (false);
	register int f = 0, a = 0, i;
	getline (cin, w);
	w = " " + w;
	if (w[w.size()-1] != ' ') w += " ";
	register int lenw = w.size ();
	for (i = 0; i < lenw; i ++) w[i] = tolower (w[i]);
	getline (cin, st);
	st = " " + st + " ";
	register int lens = st.size ();
	for (i = 0; i < lens; i ++) st[i] = tolower (st[i]);
	i = st.find (w, 0);
	if (i!=string::npos) {
		f = i;
		while (i<st.size()) {
			i = st.find (w, i+lenw-1);
			a ++;
		}
		cout << a << " " << f << endl;
	} else {
		cout << "-1" << endl;
	}
	return 0;
}
