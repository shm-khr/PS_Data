#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int n,t[100000];
	int max,M;
	int i;
	int sum;
	cin>>n;
	max=-1;
	for(i=0;i<n;i++){
		cin>>t[i];
		if(max<t[i]){
			max=t[i];
			M=i;
		}
	}
	sum=0;
	for(i=0;i<n;i++){
		if(t[M]%t[i]!=0){
			while(t[M]%t[i]!=0){
				t[i]++;
				sum++;
			}
		}
	}
	
	cout<<sum<<endl;
	
	return 0;
}
