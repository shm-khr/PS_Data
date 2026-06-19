#include <bits/stdc++.h>
using namespace std;


int main()
{
	int n;
	cin>>n;
	int ar[n],fl=0;
	for(int i=0;i<n;i++){cin>>ar[i];
    if(ar[i]%2==0){
    	if(ar[i]%3!=0 && ar[i]%5!=0)
    	{cout<<"DENIED"<<endl;
    	
    		fl=1;
    	}
    	
    }
		
		
	}
    if(fl==0)
    cout<<"APPROVED"<<endl;
	return 0;
}
