#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;

int main()
{
    int tem;
    int a, b;
    int t = 3;
    while(t--)
    {
        cin >> tem;
        if(tem == 5) a++;
        if(tem == 7) b++;
    }
    if(a == 2 && b == 7)
        puts("YES");
    else 
        puts("NO");
    return 0;
}
