#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

#define DATA_MAX 100000
#define QUERY_MAX 200000
#define ZMAX 10000

class UnionFind{
private:
    vector<map<int, int> > tree;
    
    bool Root(int now, int target, int &Sum){
        vector<bool> visit(tree.size(), false);
        map<int, int>::iterator it;
        
        visit[now] = true;
        if(now == target)
            return true;
        
        it = tree[now].find(target);
        if(it != tree[now].end()){
            Sum += tree[now][target];
            return true;
        }
        else{
            for(map<int, int>::iterator iter = tree[now].begin(); iter != tree[now].end(); iter++){
                if(Root(iter->first, target, Sum, visit)){
                    Sum += iter->second;
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool Root(int now, int target, int &Sum, vector<bool> &visit){
        map<int, int>::iterator it;
        
        visit[now] = true;
        if(now == target)
            return true;
        
        it = tree[now].find(target);
        if(it != tree[now].end()){
            Sum += tree[now][target];
            return true;
        }
        else{
            for(map<int, int>::iterator iter = tree[now].begin(); iter != tree[now].end(); iter++){
                if(!visit[iter->first]){
                    if(Root(iter->first, target, Sum, visit)){
                        Sum += iter->second;
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
public:
    UnionFind(){}
    
    UnionFind(int n){
        tree.resize(n);
    }
    
    ~UnionFind(){
        tree.clear();
        tree.shrink_to_fit();
    }
    
    void set(int x, int y, int z){
        tree[x][y] = z;
        tree[y][x] = -z;
    }
    
    void get(int x, int y){
        int S = 0;
        
        if(Root(x, y, S)){
            cout << S << endl;
            tree[x][y] = S;
            tree[y][x] = -S;
        }
        else
            cout << "?" << endl;
    }
    
};

int ReadQuery(UnionFind*, int, int);

int main(){
    UnionFind *uf;
    int n, q;
    
    cin >> n >> q;
    if(!((2 <= n && n <= DATA_MAX) && (1 <= q && q <= QUERY_MAX)))
        return -1;
    
    uf = new UnionFind(n);
    if(ReadQuery(uf, n, q) == -1)
        return -1;
    
    delete uf;
    
    return 0;
}

int ReadQuery(UnionFind *uf, int n, int q){
    int com, x, y, z;
    
    for(int i = 0; i < q; i++){
        cin >> com;
        
        if(com == 0){
            cin >> x >> y >> z;
            if(!(0 <= x && x < n) || !(0 <= y && y < n) || x == y || !(0 <= z && z <= ZMAX))
                return -1;
            
            uf->set(x, y, z);
        }
        else if(com == 1){
            cin >> x >> y;
            if(!(0 <= x && x < n) || !(0 <= y && y < n) || x == y)
                return -1;
            
            uf->get(x, y);
        }
        else
            return -1;
    }
    
    return 0;
}




