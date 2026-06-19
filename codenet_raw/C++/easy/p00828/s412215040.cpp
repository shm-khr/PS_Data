#include<cmath>
#include<iostream>
using namespace std;
#define PI 3.141592
int winding_number(int x, int y, double p[][2], int n)
{
  int xx = p[n - 1][0] - x, yy = y - p[n - 1][1] - y;
  double r1 = acos(xx / sqrt(xx * xx + yy * yy)); 
  double s = 0;
  for(int i = 0; i < n; i++)
  {
    int xx = p[i][0] - x, yy = p[i][1] - y;
    double r2 = acos(xx / sqrt(xx * xx + yy * yy));
    // y????????????????¬¬3, 4?±????
    if(yy < 0)
      r2 = PI * 2 - r2;
    double ts = r2 - r1;
    // 180???????????§?????????????????¨?????????
    if(abs(ts) > PI)
      ts = ts / abs(ts) * (PI - abs(ts));
    s += ts ;
    r1 = r2;
  }
  return abs(s) < PI ? 0 : 1;
}


double p[3][2];
int main()
{
  while(cin >> p[0][0] >> p[0][1] >> p[1][0] >> p[1][1] >> p[2][0] >> p[2][1])
  {
    double x, y;
    cin >> x >> y;
    cout << winding_number(x, y, p, 3) << endl;;
  }
}