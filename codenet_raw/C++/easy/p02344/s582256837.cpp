#include<iostream>
#include <cstdlib>
#include<vector>

using namespace std;

class UnionFindTrees{
  public:
    vector<int> rank, p, diffWeight;

    UnionFindTrees(){}
    UnionFindTrees(int size){
      rank.resize(size, 0);
      p.resize(size, 0);
      diffWeight.resize(size, 0);
      for(int i=0 ; i<size ; ++i) makeSet(i);
    }
    ~UnionFindTrees(){}

    void makeSet(int x){
      p[x] = x;
      rank[x] = 0;
      diffWeight[x] = 0;
    }

    void relate(int x, int y, int z){
      // z -= diffWeight[x];
      // z += diffWeight[y];
      z += diffWeight[y] - diffWeight[x];

      x = findSet(x);
      y = findSet(y);

      if(rank[x] > rank[y]){
        p[y] = x;
        diffWeight[y] = -z;
      }else{
        p[x] = y;
        diffWeight[x] = z;
        if(rank[x] == rank[y]) rank[y] = rank[y]+1;
      }
    }

    bool same(int x, int y){
      return findSet(x) == findSet(y);
    }

    int findSet(int x){
      if(x != p[x]){
        p[x] = findSet(p[x]);
        diffWeight[x] += diffWeight[p[x]];
      }
      return p[x];
    }

    int getWeight(int x){
      findSet(x);
      return diffWeight[x];
    }

    void diff(int x, int y){
      if(same(x, y)) cout << abs(getWeight(y)-getWeight(x)) << endl;
      else cout << "?" << endl;
    }
};

int main(){
  int n=0, q=0;
  int com=0, x=0, y=0, z=0;

  cin >> n >> q;
  UnionFindTrees uft = UnionFindTrees(n);

  for(int i=0 ; i<q ; ++i){
    cin >> com;

    if(com == 0){
      cin >> x >> y >> z;
      uft.relate(x, y, z);
    }
    else if (com == 1){
      cin >> x >> y;
      uft.diff(x, y);
    }
  }//---- end of for ----
  // for(int i=0 ;  i<n ; ++i){
  //   cout << "i=" << i << ", " << uft.p[i] << ", " << uft.rank[i]<< ", " << uft.diffWeight[i] << endl;
  // }
}

