    #include <bits/stdc++.h>
    using namespace std;
    #define rep(i, n) for (int i = 0; i < (int)(n); i++)
    #define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
    int main(){
        int a,b,m;
        cin >> a >> b >> m;
        int a_kin[a],b_kin[b];
    //    int ans_kin[(a*b)+m];
        vector<int> ans_kin((a*b)+m);
        int di[m][3];
        rep(i,a){
            cin >> a_kin[i];
        }
        rep(i,b){
            cin >> b_kin[i];
        }
        rep(i,m){
            rep(j,3){
                cin >> di[i][j];
            }
        }    
//        cout << a << " " << b << " " << m << endl;
        rep(i,a){
//            cout << a_kin[i] << " ";
        }
//        cout << endl;
        rep(i,b){
//            cout << b_kin[i] << " ";
        }
//        cout << endl;
        rep(i,m){
            rep(j,3){
//                cout << di[i][j] << " ";
            }
//            cout << endl;
        }

        int num = 0;
        rep(i,a){
            rep(j,b){
                ans_kin[num] = a_kin[i] + b_kin[j];
                num += 1;
            }
        }
        rep(i,m){
            ans_kin[num] = a_kin[di[i][0] -1] + b_kin[di[i][1] -1] - di[i][2];
            num += 1;
        }

//        cout << num << endl;
        rep(i,ans_kin.size()){
//            cout << ans_kin[i] <<" ";
        }
//        cout << endl;
        sort(ans_kin.begin(),ans_kin.end());
        cout << ans_kin[0] << endl;


    }