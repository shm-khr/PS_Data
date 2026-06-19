#include<bits/stdc++.h>
using namespace std;
typedef struct { double x,y;} point;

double nai(point a,point b){ return a.x*b.x+a.y*b.y; }

int main(){
point p1,p2;
double x,y;
cin>>x>>y;
p1.x=x;
p1.y=y;
cin>>x>>y;
p2.x=x;
p2.y=y;
point vec={p2.x-p1.x , p2.y-p1.y};
point e={vec.x/sqrt(nai(vec,vec)) , vec.y/sqrt(nai(vec,vec))};
int q;
cin>>q;
for(int i=0;i<q;i++){
cin>>x>>y;
point p;
p.x=x-p1.x;
p.y=y-p1.y;
point m;
	m.x=p1.x+nai(p,e)*e.x;
	m.y=p1.y+nai(p,e)*e.y;
point vec2={m.x-x,m.y-y};

printf("%0.9lf %0.9lf\n",x+2*vec2.x,y+2*vec2.y);


}
return 0;
}

