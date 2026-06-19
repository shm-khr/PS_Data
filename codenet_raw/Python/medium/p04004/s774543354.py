#include<iostream>
#define MOD 1000000007
#define N 1000
using namespace std;
typedef long long LL;
LL mod_pow(LL base, LL exp)
{
	if(exp==0) return 1;
	if(exp&1) return (mod_pow(base,exp-1)*base)%MOD;
	else return mod_pow((base*base)%MOD,exp/2);
}
LL fac[3*N+1];
LL fac_inv[3*N+1];
LL C(LL n, LL k)
{
	if(k < 0 || n < k) return 0;
	LL num = fac[n];
	LL den = (fac_inv[n-k]*fac_inv[k])%MOD;
	return (num*den)%MOD;
}
int main()
{
	fac[0] = 1;
	for(LL n = 1; n <= 3*N; n++)
		fac[n] = (fac[n-1]*n)%MOD;
	fac_inv[3*N] = mod_pow(fac[3*N],MOD-2);
	for(LL n = 3*N-1; n >= 0; n--)
		fac_inv[n] = (fac_inv[n+1]*(n+1))%MOD;

	LL a, b, c; cin >> a >> b >> c;
	a++;
	//WLOG, b > c
	if(!(b>c))
	{
		b = b^c;
		c = b^c;
		b = b^c;
	}

	LL ans = 0;
	LL sum = 1;
	LL pull = 0;
	for(LL n = a; n <= a+b+c; n++)
	{
		LL sub = 0;
		
		sub = (sub+sum-pull)%MOD;
		sub = (sub*C(n-2,a-2))%MOD;
		sub = (sub*mod_pow(3,a+b+c-n))%MOD;
		ans = (ans+sub)%MOD;

		sum  = (2*sum-C(n-a,c))%MOD;
		pull = (2*pull+C(n-a,n-a-b))%MOD;
	}
	cout<<(ans+MOD)%MOD<<endl;

	return 0;
}