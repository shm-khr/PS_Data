#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const long double e = 0.000000001;

long double f(long double x1,long double y1,long double x2,long double y2,long double X){
    return (y1*(x2-X)+y2*(X-x1))/(x2-x1);
}

int main(){
    while(1){
        int m;
        long double x[102],y[102];
        scanf("%d",&m);
        if(m == 0)break;
        for(int i = 0 ; i < m ; i ++){
            scanf("%Lf%Lf",&x[i],&y[i]);
        }
        x[m] = x[0];
        y[m] = y[0];
        
        int ret = 0;
        for(long double _X = -2000.0 ; _X < 2000.0 ; _X += 1.0){
        //for(long double _X = -7.0 ; _X < 5.0 ; _X += 1.0){
            vector<long double> Y[2];
            long double X[2] = { _X+e , _X+1.0-e };
            for(int i = 0 ; i < m ; i ++){
                for(int j = 0 ; j < 2 ; j ++){
                    if((x[i]-X[j])*(x[i+1]-X[j]) < 0){
                        Y[j].push_back(2500.0+f(x[i],y[i],x[i+1],y[i+1],X[j]));
                    }
                }
            }
            sort(Y[0].begin(),Y[0].end());
            sort(Y[1].begin(),Y[1].end());
            int a[5002] = {};
            /*if(Y[0].size()%2 != 0){
                puts("ERROR1");
                return 0;
            }
            if(Y[0].size() != Y[1].size()){
                puts("ERROR2");
                return 0;
            }*/
            for(int i = 0 ; i < Y[0].size() ; i += 2){
                long double l = min(Y[0][i],Y[1][i]), r = max(Y[0][i+1],Y[1][i+1]);
                //cout.precision(20);
                //cout << l << " " << r << endl;
                if((int)(l+e*e) <= (int)(r+1.0-e*e)){
                    a[(int)(l+e*e)] ++;
                    a[(int)(r+1.0-e*e)] --;
                }
            }
            //int cnt = 0;
            for(int i = 1 ; i < 5002 ; i ++){
                a[i] += a[i-1];
                if(a[i] > 0){
                    //cnt ++;
                    ret ++;
                }
            }
            /*if(cnt != 0){
                printf("%Lf %d%c",_X,cnt,10);
                break;
            }*/
        }
        cout << ret << endl;
    }
}