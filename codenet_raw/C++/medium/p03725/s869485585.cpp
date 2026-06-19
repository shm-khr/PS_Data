#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
using ll = long long;
using uint = unsigned int;
using graph = std::vector<std::vector<ll>>;
using wGraph = std::vector<std::vector<std::pair<ll,ll>>>;
#define rep(i,n) for (int i=0; i < int(n); i++)

using namespace std;
ll MOD7 = 1000000007;
ll MOD9 = 1000000009;
vector<ll> InputVec(ll N){
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    return A;
}
void OutputVec(vector<ll> A){
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ",";
    }
    cout << endl;
}
vector<vector<ll>> InputVec2d(ll H,ll W){
    vector<vector<ll>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<ll>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            cin >> A[yi][xi];
        }
    }
    return A;
}
vector<vector<char>> InputVec2dStr(ll H,ll W){
    vector<vector<char>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<char>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        string S;
        cin >> S;
        for (int xi = 0; xi < W; ++xi) {
            A[yi][xi] = S[xi];
        }
    }
    return A;
}
void OutputVec2d(vector<vector<ll>> A){
    for (int yi = 0; yi < A.size(); ++yi) {
        for (int xi = 0; xi < A[yi].size(); ++xi) {
            cout << A[yi][xi] << ",";
        }
        cout << endl;
    }
}
graph InputGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    return G;
}
graph InputDGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
    }
    return G;
}
void OutputGraph(graph G){
    for (int i = 0; i < G.size(); ++i) {
        cout << i << ":";
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j]<< ",";
        }
        cout << endl;
    }
}
void OutputAnswerBool(bool b,bool isUpperCase = false){
    if(b){
        if(isUpperCase){
            cout << "YES" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }else{
        if(isUpperCase){
            cout << "NO" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

int main() {
    ll H,W,K;
    cin >> H >> W >> K;
    auto S = InputVec2dStr(H,W);
    ll sx,sy;
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            if(S[yi][xi] == 'S'){
                sy = yi;sx = xi;
            }
        }
    }
    queue<pair<ll,ll>> q;
    q.push(make_pair(sx,sy));
    vector<vector<ll>> im(H);
    for (int yi = 0; yi < H; ++yi) {
        im[yi] = vector<ll>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            im[yi][xi] = -1;
        }
    }
    im[sy][sx] = 0;
    while(!q.empty()){
        auto current = q.front();q.pop();
        if(current.first!=0 && S[current.first-1][current.second]=='.' && im[current.first-1][current.second] == -1){
            im[current.first-1][current.second] = im[current.first][current.second]+1;
            q.push(make_pair(current.first-1,current.second));
        }
        if(current.first!=H && S[current.first+1][current.second]=='.' && im[current.first+1][current.second] == -1){
            im[current.first+1][current.second] = im[current.first][current.second]+1;
            q.push(make_pair(current.first+1,current.second));

        }
        if(current.second!=0 && S[current.first][current.second-1]=='.' && im[current.first][current.second-1] == -1){
            im[current.first][current.second-1] = im[current.first][current.second]+1;
            q.push(make_pair(current.first,current.second-1));

        }
        if(current.second!=W && S[current.first][current.second+1]=='.' && im[current.first][current.second+1] == -1){
            im[current.first][current.second+1] = im[current.first][current.second]+1;
            q.push(make_pair(current.first,current.second+1));

        }
    }
    //OutputVec2d(im);
    queue<pair<ll,ll>> cq;
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            if(0 <= im[yi][xi] && im[yi][xi] <= K){
                cq.push(make_pair(yi,xi));
            }
        }
    }
    ll m = 1ll << 50;
    while (!cq.empty()){
        auto current = cq.front();cq.pop();
        ll res = min(min(current.first - 0,H - current.first),min(current.second - 0,W - current.second));
        m = min(m,(ll)ceil((double)res/(double)K)+1);
    }
    cout << m << endl;

}
