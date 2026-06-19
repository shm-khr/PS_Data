#include <iostream>
using namespace std;
 
int a[100];
 
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	int najveci = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (najveci < a[i])
		najveci = a[i];
	}
	najveci = najveci/2;
	int c=0;
	for (int i = 0; i < n; i++)
	{
		c = c + a[i];	
	}
	cout << c;
}