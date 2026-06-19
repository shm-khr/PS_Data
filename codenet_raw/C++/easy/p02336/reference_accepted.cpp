#include<bits/stdc++.h>
using namespace std;
using Int = long long;

template<Int MOD = 1000000007>
struct Mod{
  Int prev=0;
  vector<Int> fact,inv,finv;
  Mod(){}
  Mod(Int n){init(n);}
  
  Int pow(Int x,Int n){
    Int res=1;
    while(n){
      if(n&1) (res*=x)%=MOD;
      (x*=x)%=MOD;
      n>>=1;
    }
    return res;
  }
  
  Int inverse(Int a){
    return pow(a,MOD-2);
  }
  
  void init(Int n){
    if(prev>=n) return;
    prev=n;
    fact=inv=finv=vector<Int>(n);
    
    fact[0]=1;
    for(Int i=1;i<n;i++)
      fact[i]=(fact[i-1]*i)%MOD;
    
    inv[1]=1;
    for(Int i=2;i<n;i++)
      inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    
    finv[0]=1;
    for(Int i=1;i<n;i++)
      finv[i]=finv[i-1]*inv[i]%MOD;
  }
  
  Int comb(Int n,Int k){
    Int res=1;
    for(Int i=0;i<k;i++){
      res*=(n-i)%MOD;
      res%=MOD;
      res*=inverse(i+1);
      res%=MOD;
    }
    return res;
  }
  
  //only for prime MOD
  Int C(Int n,Int k){
    if(k<0||k>n) return 0;
    return fact[n]*finv[k]%MOD*finv[n-k]%MOD;
  }

  Int H(Int n,Int k){
    return C(n+k-1,n);
  }
  
  Int montmort(Int n){
    Int res=0,rinv=1;
    for(Int k=2;k<=n;k++){
      (rinv*=inverse(k))%=MOD;
      if(k%2) (res+=MOD-rinv)%=MOD;
      else (res+=rinv)%=MOD;
    }
    for(Int i=1;i<=n;i++)
      (res*=i)%=MOD;
    return res;
  }
  
  // calculate P(t) from given points in [0,N]
  Int LagrangePolynomial(vector<Int> &y,Int t){
    Int n=y.size()-1;
    init(n+1);
    Int num=1;
    for(Int i=0;i<=n;i++)
      num=num*((t-i)%MOD)%MOD;
    Int res=0;
    for(Int i=0;i<=n;i++){
      Int tmp=(y[i]*num%MOD)*inverse((t-i)%MOD)%MOD;
      tmp=tmp*finv[i]%MOD;
      tmp=tmp*finv[n-i]%MOD;
      if((n-i)&1) tmp=MOD-tmp;
      res=(res+tmp)%MOD;
    }
    return res;
  }
};

//INSERT ABOVE HERE
signed main(){
  const Int MOD = 1e9+7;
  Mod<MOD> mod(2e5);
  Int n,k;
  cin>>n>>k;
  cout<<mod.C(n-1,k-1)<<endl;
  return 0;
}

