#include<cstdio>
using namespace std;
inline int read(int &x){
	x=0;char c;bool f=0;
	while((c=getchar())>'9'||c<'0')if(c=='-')f=!f;x=c-48;
	while((c=getchar())<='9'&&c>='0')x=x*10+c-48;
	if(f)x=-x;
} 
int n,a[1001];
void sw(int i,int j){
	int x;
	while(i!=j){
		x=a[i];a[i]=a[i-1];a[i-1]=x;
		i--;
	}
}
int main(){
	read(n);read(a[1]);
	int i,j,p1,p2,sum=0,s;
	for(i=2;i<=n;i++){
		read(a[i]);
		if(a[i]>=a[i-1])continue;
		j=i-1;
		while(a[i]<a[j]&&j>1)j--;
		p1=i-j;p2=a[i-1]-a[i];
		if(p1>=p2){a[i]=a[i-1];sum+=p2;}
		else {sw(i,j);sum+=p1;}
	}
	for(i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
	printf("%d\n",sum);
}