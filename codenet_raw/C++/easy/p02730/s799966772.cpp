#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
    int n;
	for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			cout << "No" << "\n";
			return 0;
		}
	}

	 n = (s.size() - 1) / 2;

	for (int i = 0, j = n - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			cout << "No" << "\n";
			return 0;
		}
	}
     
    n = (s.size() + 3) / 2; 
    
	for (int i = n - 1, j = s.size() - 1; i < j; i++, j--) {
		if (s[i] != s[j]) {
			cout << "No" << "\n";
			return 0;
		}
	}
    
    cout << "Yes" << "\n";
    return 0;
}