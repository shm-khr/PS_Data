#include <bits/stdc++.h>
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define pr(...) cerr<< GET_MACRO(__VA_ARGS__,pr6,pr5,pr4,pr3,pr2,pr1)(__VA_ARGS__) <<endl
#define pr1(a) (#a)<<"="<<(a)<<" "
#define pr2(a,b) pr1(a)<<pr1(b)
#define pr3(a,b,c) pr1(a)<<pr2(b,c)
#define pr4(a,b,c,d) pr1(a)<<pr3(b,c,d)
#define pr5(a,b,c,d,e) pr1(a)<<pr4(b,c,d,e)
#define pr6(a,b,c,d,e,f) pr1(a)<<pr5(b,c,d,e,f)
#define pr7(a,b,c,d,e,f,g) pr1(a)<<pr6(b,c,d,e,f,g)
#define pr8(a,b,c,d,e,f,g,h) pr1(a)<<pr7(b,c,d,e,f,g,h)
using namespace std;
using Int = long long;
using ll = long long;
using Double = long double;
const Int INF = (1LL<<60); // ~ 10^18
const Int mod = (1e9)+7;
const Double EPS = 1e-8;
const Double PI = 6.0 * asin((Double)0.5);
using P = pair<Int,Int>;
using T = tuple<Int,Int,Int>;
template<class T> T Max(T &a,T b){return a=max(a,b);}
template<class T> T Min(T &a,T b){return a=min(a,b);}
ostream& operator<<(ostream& o,P p){return o<<"("<<p.first<<","<<p.second<<")";}
ostream& operator<<(ostream& o,T t){return o<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
istream& operator>>(istream& i,P &p){return i>>p.first>>p.second;}
ostream& operator<<(ostream& o,vector<auto> &a){Int i=0;for(auto t:a)o<<(i++?" ":"")<<t;return o;}
istream& operator>>(istream& i,vector<auto> &a){for(auto &t:a)i>>t;return i;}
void prArr(auto a,string s=" "){Int i=0;for(auto t:a)cout<<(i++?s:"")<<t;cout<<endl;}

template <Int X/*文字の種類*/>
class Trie{
public:
  struct Node{
    char c;         //今の文字
    Int pre;        //前の頂点番号
    Int val;        //
    Int exist;      //単語が存在するか
    vector<Int> to; //次の頂点番号
    Node(){};
    Node(char c,Int pre,Int val=0,Int exist=0):c(c),pre(pre),val(val),exist(exist),to(X,-1){};
  };
   
  vector<Node> v;
  function<Int(char)> toI; //文字から数字に変換する関数
   
  Trie(function<Int(char)> toI=[](char ch){return ch-'A';} ,char c = '$')
    :toI(toI){v.push_back(Node(c,-1,0/*!!!!!*/));};
 
  Int size(){return v.size();}
  void Assert(Int pos){assert(0 <= pos && pos<(Int)v.size());}
  Int go(Int pos,char c){Assert(pos);return v[pos].to[toI(c)];}
  Int go(const string &s,Int pos = 0){
    for(char c:s){
      pos = go(pos,c);
      if(pos == -1) return -1;
    }
    return pos;
  }
  Int back(Int pos){Assert(pos);return v[pos].pre;}
  Int getVal(Int pos){Assert(pos);return v[pos].val;} //0だったら単語が存在しない。
  Int exist(Int pos){Assert(pos);return v[pos].exist;}
   
  void add(const string &s,Int val = 1){
    Int pos = 0;
    for(char c:s){
      if(go(pos,c) != -1){pos = go(pos,c);continue;}
      v.push_back(Node(c,pos));
      pos = v[pos].to[toI(c)] = v.size()-1;
    }
    v[pos].exist = 1;
    v[pos].val = max(v[pos].val, val);  //min,max,+ 臨機応変に変えて
  }
};
 
Int m;
Trie <26> trie([](char ch){return ch - 'a';});
vector<vector<char> > Ch;
 
vector<map<Int,Int> > mem;
Int dfs(Int pos,Int len){
  if(pos == -1) return 0;
  if(len == m) return trie.exist(pos);
  if(mem[pos].count(len)) return mem[pos][len];
   
  Int res = 0;
  {
    for(char ch = 'a'; ch <= 'z'; ch++){
      Int a =  dfs(trie.go(pos, ch), len+1);
      Int b =  trie.exist(pos)? dfs(trie.go(0, ch), len+1):0;
      res = min(INF, res + a + b);
      if(res == INF) break;
    }
  }
  return mem[pos][len] = res;
}

bool overflow(ll a,ll b){return a!=0 && b!= 0 && a > LONG_MAX/b;}

Int mult(Int a,Int b){
  if(overflow(a, b) || overflow(b, a)) return INF;
  return min(INF, a * b);
}
 
string ans;
void restore(const map<Int,Int> &Pos,Int len,Int K){
  if(len == m) return;
   
  char to = -1;
  Int sum = 0;
  {
    for(char ch = 'a'; ch <= 'z'; ch++){
      Int s = 0;
      for(const auto t:Pos){
	Int pos = t.first;
	Int val = t.second;
	Int a = mult(val , dfs(trie.go(pos, ch), len+1));
	Int b = trie.exist(pos)?  mult(val , dfs(trie.go(0, ch), len+1)):0;
	s = min(INF, s + min(INF,a + b));
      }
      if(sum + s >= K) {to = ch; break;}
      sum += s;
       
    }
  }
 
  if(to == -1){ans = "-";return;}
   
  {
    ans += to;
    map<Int,Int> To;
    for(auto t:Pos){
      Int pos = t.first;
      Int val = t.second;
      if(dfs(trie.go(pos, to), len+1)) To[trie.go(pos, to)] += val;
      if(trie.exist(pos) && dfs(trie.go(0,to), len+1)) To[trie.go(0,to)] += val;
    }
    restore(To, len+1, K - sum);
  }
}
 
signed main(){
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);
  Int n, K;
  cin>>n>>m>>K;
 
  for(Int i=0;i<n;i++){
    string s;
    cin>>s;
    trie.add(s);
  }
  
  mem.resize(trie.size());
  //pr(trie.size(), dfs(0,0));
  map<Int,Int> Pos; Pos[0] = 1;
  restore(Pos, 0, K);
  cout<<ans<<endl;
  return 0;
}

