#include <bits/stdc++.h>
using namespace std;
int k;
int calc(int num)
{
    int count = 1;
    if(num <= k) return count;
    if((num-k) % (k-1) == 0) count += (num-k)/(k-1);
    else count += (num-k)/(k-1) + 1;
    return count;
}

int main()
{
    int n;
    cin >> n >> k;
    int pos = 0;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a == 1)
        {
            pos = i;
        }
    }
    if(pos == 0 || pos == n-1)
    {
        int a = calc(n);
        cout << a << endl;
    }
    else
    {
        int a = calc(n-pos);
        int b = calc(pos+1);
        cout << a + b << endl;
    }
}
