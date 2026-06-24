#include<iostream>
using namespace std;
int main()
{
  string s;
  cin >>s;
	if(s[s.length()-1]!='s')
      s+='s';
  	else if(s[s.length()-1)=='s')
      s+='es';
    cout <<s<<endl;
  return 0;
}