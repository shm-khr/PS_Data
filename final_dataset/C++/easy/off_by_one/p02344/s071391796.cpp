#include <bits/stdc++.h>
using LL = long long;
using namespace std;
class UnionFind{
private:
    vector<int> data;
    vector<LL> diff_weight;
public:
    UnionFind(int size) : data(size,-1), diff_weight(size, 0){}
    int root(int x){
        if(data[x] < 0){
            return x;
        }else{
            diff_weight[x] += diff_weight[data[x]];
            return data[x] = root(data[x]);
        }
    }
    int weight(int x){
        root(x);
        return diff_weight[x];
    }
    bool connect(int x,int y, LL w){

        w += weight(x);w -= weight(y);
        x = root(x);y = root(y);
        if(x != y){
            if(data[x] > data[y])swap(x,y), w = -w;
            data[x] += data[y];data[y] = x;
            diff_weight[y] = w;
        }
        return x != y;
    }
    bool check(int x,int y){
        return root(x) == root(y);
    }
    int Size(int x){
        return -data[x];
    }
    int diff(int a, int b){
        return weight(b) - weight(a);
    }
};

int main(){
   int N,q;cin >> N >> q;
   UnionFind Uni(N);
   for(int a = 0;a < q;a++){
       int x;cin >> x;
       if(x == 0){
           int d,e,f;cin >> d >> e >> f;
           Uni.connect(d,e,f);
       }else{
           int d,e;cin >> d >> e;
           if(Uni.check(d,e))cout<<Uni.diff(d,e)<<endl;
           else cout<<"?"<<endl;
       }
   }
}

