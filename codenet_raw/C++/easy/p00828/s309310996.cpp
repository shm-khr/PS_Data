#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,m,p;
	while(cin>>n>>m>>p){
		if(n==0&&m==0&&p==0) break;
		int a[n+1][n+1][n+1];
		for(int x=1;x<=n;x++){
			for(int y=1;y<=n;y++){
				for(int z=1;z<=n;z++){
					a[x][y][z]=0;
				}
			}
		}
		int x,y,z,teban=1,flg=0;
		for(int i=1;i<=p;i++){
			cin>>x>>y;
			for(int zz=1;zz<=n;zz++){
				if(a[x][y][zz]==0){
					a[x][y][zz]=teban;
					z=zz;
					break;
				}
			}
			//x?????????
			for(int j=x-m+1;j<=x;j++){
				if(j>=1&&j+m-1<=n){
					int iro=a[j][y][z];
					for(int k=1;k<=m-1;k++){
						if(a[j+k][y][z]!=iro){
							goto d1;
						}
					}
					flg=1;
					d1:;
				}
			}
			//y?????????
			for(int j=y-m+1;j<=y;j++){
				if(j>=1&&j+m-1<=n){
					int iro=a[x][j][z];
					for(int k=1;k<=m-1;k++){
						if(a[x][j+k][z]!=iro){
							goto d2;
						}
					}
					flg=1;
					d2:;
				}
			}
			//z?????????
			for(int j=z-m+1;j<=z;j++){
				if(j>=1&&j+m-1<=n){
					int iro=a[x][y][j];
					for(int k=1;k<=m-1;k++){
						if(a[x][y][j+k]!=iro){
							goto d3;
						}
					}
					flg=1;
					d3:;
				}
			}
			//x+y
			for(int j=1-m;j<=0;j++){
				if(x+j>=1&&y+j>=1&&x+j+m-1<=n&&y+j+m-1<=n){
					int iro=a[x+j][y+j][z];
					for(int k=1;k<=m-1;k++){
						if(a[x+j+k][y+j+k][z]!=iro){
							goto d4;
						}
					}
					flg=1;
					d4:;
				}
			}
			//x-y
			for(int j=1-m;j<=0;j++){
				if(x+j>=1&&y-j<=n&&x+j+m-1<=n&&y-j-m+1>=1){
					int iro=a[x+j][y-j][z];
					for(int k=1;k<=m-1;k++){
						if(a[x+j+k][y-j-k][z]!=iro){
							goto d5;
						}
					}
					flg=1;
					d5:;
				}
			}
			//x+z
			for(int j=1-m;j<=0;j++){
				if(x+j>=1&&z+j>=1&&x+j+m-1<=n&&z+j+m-1<=n){
					int iro=a[x+j][y][z+j];
					for(int k=1;k<=m-1;k++){
						if(a[x+j+k][y][z+j+k]!=iro){
							goto d6;
						}
					}
					flg=1;
					d6:;
				}
			}
			//x-z
			for(int j=1-m;j<=0;j++){
				if(x+j>=1&&z-j<=n&&x+j+m-1<=n&&z-j-m+1>=1){
					int iro=a[x+j][y][z-j];
					for(int k=1;k<=m-1;k++){
						if(a[x+j+k][y][z-j-k]!=iro){
							goto d7;
						}
					}
					flg=1;
					d7:;
				}
			}
			//y+z
			for(int j=1-m;j<=0;j++){
				if(y+j>=1&&z+j>=1&&y+j+m-1<=n&&z+j+m-1<=n){
					int iro=a[x][y+j][z+j];
					for(int k=1;k<=m-1;k++){
						if(a[x][y+j+k][z+j+k]!=iro){
							goto d8;
						}
					}
					flg=1;
					d8:;
				}
			}
			//y-z
			for(int j=1-m;j<=0;j++){
				if(y+j>=1&&z-j<=n&&y+j+m-1<=n&&z-j-m+1>=1){
					int iro=a[x][y+j][z-j];
					for(int k=1;k<=m-1;k++){
						if(a[x][y+j+k][z-j-k]!=iro){
							goto d9;
						}
					}
					flg=1;
					d9:;
				}
			}
			//x+y+z
			for(int j=1-m;j<=0;j++){
				if(x+j>=1&&y+j>=1&&z+j>=1&&x+j+m-1<=n&&y+j+m-1<=n&&z+j+m-1<=n){
					int iro=a[x+j][y+j][z+j];
					for(int k=1;k<=m-1;k++){
						if(a[x+j+k][y+j+k][z+j+k]!=iro){
							goto d10;
						}
					}
					flg=1;
					d10:;
				}
			}
			//x+y-z
			for(int j=1-m;j<=0;j++){
				if(x+j>=1&&y+j>=1&&z-j<=n&&x+j+m-1<=n&&y+j+m-1<=n&&z-j-m+1>=1){
					int iro=a[x+j][y+j][z-j];
					for(int k=1;k<=m-1;k++){
						if(a[x+j+k][y+j+k][z-j-k]!=iro){
							goto d11;
						}
					}
					flg=1;
					d11:;
				}
			}
			//x-y+z
			for(int j=1-m;j<=0;j++){
				if(x+j>=1&&y-j<=n&&z+j>=1&&x+j+m-1<=n&&y-j-m+1>=1&&z+j+m-1<=n){
					int iro=a[x+j][y-j][z+j];
					for(int k=1;k<=m-1;k++){
						if(a[x+j+k][y-j-k][z+j+k]!=iro){
							goto d12;
						}
					}
					flg=1;
					d12:;
				}
			}
			//x+y-z
			for(int j=1-m;j<=0;j++){
				if(x+j>=1&&z-j<=n&&y+j>=1&&x+j+m-1<=n&&z-j-m+1>=1&&y+j+m-1<=n){
					int iro=a[x+j][y+j][z-j];
					for(int k=1;k<=m-1;k++){
						if(a[x+j+k][y+j+k][z-j-k]!=iro){
							goto d13;
						}
					}
					flg=1;
					d13:;
				}
			}
			if(flg==1){
				if(teban==1){
					cout<<"Black";
				}
				else{
					cout<<"White";
				}
				cout<<" "<<i<<endl;
				for(int aa=i+1;aa<=p;aa++){
					cin>>x>>y;
				}
				goto end;
			}
			if(teban==1) teban=2;
			else teban=1;
		}
		cout<<"Draw"<<endl;
		end:;
	}
    return 0;
}