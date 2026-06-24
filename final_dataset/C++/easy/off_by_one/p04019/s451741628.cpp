#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    int x = 0, y = 0;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == 'E') x++;
        if (S[i] == 'W') x--;
        if (S[i] == 'N') y++;
        if (S[i] == 'S') y--;
        if (x == 0 && y == 0) {
            printf("%s\n", "Yes");
            return 0;
        }
    }
    printf("%s\n", "No");
    return 0;
}
