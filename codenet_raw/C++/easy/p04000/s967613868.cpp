#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
deque<int> deq;
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

int num[10];
vector<pair<int,int>> ss;

int main(){
    int h,w,n;
    cin >> h>> w>>n;
    
    rep(i,n){
        int a,b;
        cin >> b>>a;
        for(int k=-1;k<=1;k++){
            for(int l=-1;l<=1;l++){
                int x,y;
                x=a+k;y=b+l;
                if(x<=1||x>=w||y<=1||y>=h){
                    continue;
                }else{
                    ss.push_back(mp(x,y));
                }
            }
        }
    }
    sort(ss.begin(),ss.end());
    pair<int,int> temp=mp(-1,-1);
    int numt=0;
    rep(i,ss.size()){
        int x=ss[i].first;
        int y=ss[i].second;
        if(i==0){
            temp=mp(x,y);
            numt=1;
        }else if(temp.first==x&&temp.second==y){
            numt++;
            if(i==ss.size()-1){
                num[numt]++;
                //cerr<<x<<y<<' '<<numt<<endl;
            }
        }else{
            num[numt]++;
            //cerr<<x<<y<<' '<<numt<<endl;
            numt=1;
            temp=mp(x,y);
        }
    }
    num[0]=(h-2)*(w-2);
    rep2(i,9){
        num[0]-=num[i];
    }
    rep(i,10){
        cout<<num[i]<<endl;
    }
    return 0;
}