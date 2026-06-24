#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define ll long long
#define pii pair<int, int>
#define is insert
#define er erase

using namespace std;

const int MAX_N = 2e5 + 1;

int solve();

#define TASK ""

int main()
{
    #ifdef DEBUG
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
        freopen(TASK".in", "r", stdin);
        freopen(TASK".out", "w", stdout);
    #endif // DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}

int n;

int a[MAX_N];

int eraseFromRight(set<pii> & s, int margin)
{
    while (!s.empty())
    {
        pii it = *s.rbegin();
        if (it.X > margin)
        {
            s.er(it);
        }
        else
        {
            break;
        }
    }
}

set<pii> :: iterator findLetter(set<pii> & s, int pos)
{
    if (s.empty())
    {
        return s.end();
    }
    set<pii> :: iterator it = s.upper_bound(mp(pos, -1));
    if (it == s.begin())
    {
        return s.end();
    }
    else
    {
        it--;
        if (it -> X == pos)
        {
            return it;
        }
        else
        {
            return s.end();
        }
    }
}

bool add(set<pii> & s, int pos, int x)
{
    if (pos == 0)
    {
        return false;
    }
    set<pii> :: iterator it = findLetter(s, pos);
    if (it == s.end())
    {
        if (x == 1)
        {
            return false;
        }
        s.is(mp(pos, 2));
    }
    else if (it -> Y < x)
    {
        pii cur = *it;
        s.er(it);
        cur.Y++;
        s.is(cur);
    }
    else
    {
        s.er(it);
        return add(s, pos - 1, x);
    }
    return true;
}

bool check(int x)
{
    set<pii> s;
    for (int i = 2; i <= n; ++i)
    {

        if (a[i] <= a[i - 1])
        {
            eraseFromRight(s, a[i]);
            bool t = add(s, a[i], x);
            if (!t)
            {
                return false;
            }
        }
    }
    return true;
}

int solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int l = 0;
    int r = MAX_N;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (check(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}


