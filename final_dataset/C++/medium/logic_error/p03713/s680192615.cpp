#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

long long Diff(long H, long W)
{
	long long Smax, Smin, Diff =0;

	long  H1 = (long) (H / 3.0);
	long  H2 = (long)((H - H1) / 2.0);
	Diff= W*min( H1, min( H2, H - H2-H1 ));
	
	H1 = (long)(H / 2.0);
	H2 = H - H1;
	long W1 = (long)(2*W/ 3.0);
	Smax = max(H2*W1, H*(W- W1));
	Smin = min(H1*W1, H*(W - W1));
	Diff = min(Diff, Smax - Smin);
	Smax = max(H2*(W1+1), H*(W - W1-1));
	Smin = min(H1*(W1+1), H*(W - W1-1));
	Diff = min(Diff, Smax - Smin);
	return Diff;
}
int main()
{
	int H, W;
	cin >> H >> W;
	cout << min(Diff(H, W), Diff(W, H));

	return 0;
}