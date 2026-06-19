#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> vec(3);
  cin >> vec.at(0) >> vec.at(1) >> vec.at(2);

  sort(vec.begin(), vec.end());

  if (vec.at(0) == 5 && vec.at(1) == 5 && vec.at(2) == 7)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}
