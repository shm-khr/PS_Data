#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
	int lop;
	for (cin >> lop; lop > 0; lop--) {
		string a; cin >> a;
		string b; cin >> b;
		string c, d;
		int dif = a.size() - b.size();
		bool kuri = 0;
		for (int lop = 0; lop < abs(dif); lop++) {
			d += '0';
		}
		if (dif > 0)
			b = d + b;
		if (dif < 0)
			a = d + a;
		for (int i = 0; i < a.size(); i++) {
			c += '\0';
		}
		for (int i = a.size()-1; i >= 0; i--) {
			c[i] = a[i] + b[i]+kuri-'0';
			//cout << "c["<<i<<"] = "<<c[i] << endl;
			kuri = 0;
			if (c[i] > '9') {
				c[i] -= 10;
				kuri = 1;
			}
			if (i == 0 && kuri == 1)
				c = '1' + c;
		}
		if (c.size() > 80)
			cout << "overflow\n";
		else
			cout << c << endl;
	}
	return 0;
}
