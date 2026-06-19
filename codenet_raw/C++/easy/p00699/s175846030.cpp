#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)(n);i++)

typedef pair<int, int> result;

result Areas(const string &s, int p = 0);
result OneArea(const string &s, int p = 0);

int majority(int n) {
  return n / 2 + 1;
}

int majority(vector<int> v) {
/*  cout << "majority called: ";
  REP(i, v.size()) {
    cout << v[i] << " ";
  }
  cout << endl;*/

  int sum = 0, least = majority(v.size());
  sort(v.begin(), v.end());
  for (int i = 0; i < least; i++) { sum += v[i]; }

  return sum;
}

result OneArea(const string &s, int p) {
/*  cout << "OneArea called: '" << s.substr(p) << "'" << endl;*/
  p++;
  if (isdigit(s[p])) {
    int people = 0;
    while (isdigit(s[p])){ people = people * 10 + (s[p++] - '0'); }
    p++;
/*    printf("OneArea returns: (%d, %s)\n", 
        majority(people), s.substr(p).c_str());*/
    return result(majority(people), p);
  } else {
    result r = Areas(s, p);
    r.second ++;
/*    printf("OneArea returns: (%d, %s)\n", 
        r.first, s.substr(r.second).c_str()); */
    return r;
  }
}

result Areas(const string &s, int p) {
/*  cout << "Areas called: '" << s.substr(p) << "'" << endl; */

  vector<int> areas;
  while(s[p] == '[') {
    result r = OneArea(s, p);
    areas.push_back(r.first);
    p = r.second;
  }
/*  printf("Areas returns: (%d, %s)\n",
      majority(areas), s.substr(p).c_str()); */
  return result(majority(areas), p);
}


int main() {
  int n;
  cin >> n;
  REP(i, n) {
    string s;
    cin >> s;
    result r = OneArea(s);
    cout << r.first << endl;
  }
}