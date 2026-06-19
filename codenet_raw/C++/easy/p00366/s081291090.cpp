#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int n,t[100000];
	int max,M;
	int i,j;
	int sum;
	int cnt,cnt2,MC[1000];
	cin>>n;
	max=-1;
	for(i=0;i<n;i++){
		cin>>t[i];
		if(max<t[i]){
			max=t[i];
			M=i;
		}
	}
	cnt=0; cnt2=2;
	while(1){
//		cout<<"@"<<max<<endl;
		MC[cnt]=max;
		if(max==1) break;
		while(1){
			if(max%cnt2==0){
				max/=cnt2;
				break;
			}
			else cnt2++;
		}
		cnt++;
	}
//	for(i=0;i<cnt;i++) cout<<MC[i]<<" ";
//	cout<<endl;
	sum=0; cnt--;
	for(i=0;i<n;i++){
		if(t[M]%t[i]!=0){
			for(j=cnt;j>=0;j--){
				if(MC[j]>t[i]){
					sum+=MC[j]-t[i];
//					cout<<"sum="<<sum<<endl;
					break;
				}
			}
		}
	}
	
	cout<<sum<<endl;
	
	return 0;
}
