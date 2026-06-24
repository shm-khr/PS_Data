#include<stdio.h>
#include <iostream>
#include <map>

using namespace std;
int n;//??????
int b;
int c;
int po0;
int i;
int i2;
int d=-1;
bool dame[100000];
map<int,int>name;
int po;

int main(){
	for(i=0;i<100000;i++){
			dame[i]=false;
		}
for(i2=0;d==-1;i2++){	
		po=0;
		scanf("%d",&n);
		if(n==0){
			d=i2;
			break;
		}
	    for(i=0;i<n;i++){
			scanf("%d %d",&b,&c);
		  name.insert(map<int,int>::value_type(c,b));
	    }
	map<int,int>::iterator it=name.begin();
		
        while(it!=name.end()&&dame[i2]!=true){
		    po=po+(*it).second;
			if((*it).first < po) {
			dame[i2]=true;
			}
			++it;
	    }
	name.clear();
}
	
	for(i=0;i<d;i++){
		if(dame[i]==true)cout<<"No\n";
	    else cout<<"Yes\n";
	}
return 0;
}