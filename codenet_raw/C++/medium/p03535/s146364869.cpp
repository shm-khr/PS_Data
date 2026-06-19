#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define clr(a,v) memset((a),(v),sizeof(a))

int N, D[50], b[50];
int cnt[13];
int used;

int main()
{
  scanf( "%d", &N );
  rep( i, N )
    scanf( "%d", D+i ), ++cnt[D[i]], used |= 1<<D[i];

  if( cnt[0] >= 1 || cnt[12] >= 2 )
  {
    puts("0");
    
    return 0;
  }

  rep( i, 13 ) if( cnt[i] >= 3 )
  {
    puts("0");

    return 0;
  }

  if( N < 14 )
  {
    int ans = 0;
    D[N] = 0;
    for( int i = 0; i <= (1<<14); ++i )
    {
      int mi = 1<<30;
      rep( j, N+1 )
        b[j] = D[j]+(i>>j&1?24-2*D[j]:0);

      rep( j, N+1 ) rep( k, N+1 ) if( j != k )
        mi = std::min( mi, std::min( abs(b[k]-b[j]), 24-abs(b[k]-b[j]) ) );

      ans = std::max( ans, mi );
    }

    if( N == 1 )
      ans = std::min( D[0], 24-D[0] );

    printf( "%d\n", ans );
  }

  return 0;
}