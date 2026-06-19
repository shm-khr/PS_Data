#include <iostream>
#include <string>
using namespace std;
int main()
{
	string ch;
	cin >> ch;
	bool kq=true;
	for(int i=1; i<ch.size(); i++)
	{
		if(ch[i]!=ch[i-1]) 
		{
			kq=false;
			break;
		}
	}
	cout << (kq==true?"YES":"NO");
}