#include<set>
#include<vector>
#include<cmath>
#include<utility>
#include<iomanip>
#include<iostream>
#define F(A, B) for(int A=0; A<B; A++)
using namespace std;

int main(){
	int R, n;

	cin >> R >> n;
	while(!(R==0 && n==0) ){
		int pos[41][2]={ {0, 0} };
		int l, r, h;
		F(i, n){
			cin >> l >> r >> h;
			for(int j=l+20; j<=r+20; j++){
				int tmph=h;
				if(j!=l+20 && j!=r+20){
					if(tmph > pos[j][0]){
						pos[j][0]=tmph;
					}
					if(tmph > pos[j][1]){
						pos[j][1]=tmph;
					}
				}else{
					if(tmph > pos[j][0])swap(tmph, pos[j][0]);
					if(tmph > pos[j][1])swap(tmph, pos[j][1]);
				}
			}
		}

		double min=100;
		for(int i=20-R+1; i<=20+R-1; i++){
			double tmp=pos[i][1]-sqrt(static_cast<double>(R*R-(i-20>0 ? i-20:20-i)*(i-20>0 ? i-20:20-i) ) );
			if(min > tmp)min = tmp;
		}
		if(min <= -R){
			min = 0;
		}else{
			min = min+R;
		}
		cout << fixed << setprecision(4) << min << endl;

		cin >> R >> n;
	}

}