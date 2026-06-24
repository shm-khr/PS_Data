#include<bits/stdc++.h>
#define ll      long long
#define pb      push_back
#define F	    first
#define S	    second
#define B	    begin()
#define E	    end()
#define pll     pair < ll , ll >
#define all(v)  ( v.begin() , v.end() )
#define FASTIO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std ;
int main ()
{
    int n , k ;
    cin >> n >> k ;
    vector < int > a(n) ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> a[i] ;
    ll sum = 0 , r = 0 , ans = 0 ;
    for ( ll i = 0 ; i < n ; i++ )
    {
		while( sum < k && r < n )
		{
			sum += a[r];
			r++;
		}
		if( sum < k )
		{
			break ;
		}
		ans += (n - r + 1);

		sum -= a[i];
	}
	cout << ans << endl;
}
