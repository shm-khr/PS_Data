#include <iostream>

using namespace std;

int main()
{
   int n , sum ;
   cin >> n ;

   for (int x =1 ; x<= n ; x++)
   {
       for (int y =1 ; y<=n ; y++)
       {
           if ( x %2 != 0 && y %2 ==0)
           sum ++ ;
           else if ( x % 2 ==0 && y %2 !=0)
            sum ++ ;

       }
   }
    cout << sum/2 ;
    return 0;
}
