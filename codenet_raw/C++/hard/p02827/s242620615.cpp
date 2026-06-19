#include <bits/stdc++.h>

int main(){
    using namespace std;
    constexpr unsigned long maxN = 50000;
    unsigned long N, M, T;
    cin >> N >> M >> T;
    if(T == 1){
        vector<unsigned long> state(M), gue(N, 0);
        vector<pair<unsigned long, unsigned long>> edge(M);
        vector<bitset<maxN>> reachable(N);
        for(unsigned long i{0}; i < N; ++i)reachable[i][i] = true;
        for(auto& i : edge){
            cin >> i.first >> i.second;
            --i.first;
            --i.second;
            reachable[i.first] |= reachable[i.second] |= reachable[i.first];
        }
        [&]{
            for(unsigned long i{0}; i < N; ++i)if(reachable[i].count() == N){
                gue[i] = 1;
                return;
            }
            puts("-1");
            exit(0);
        }();
        reverse(edge.begin(), edge.end());
        for(unsigned long i{0}; i < M; ++i){
            if(gue[edge[i].second]){
                state[M - i - 1] = 1;
                gue[edge[i].second] = 1;
            }else gue[edge[i].first] = 1;
        }
        for(const auto& i : state)putchar(94 ^ 40 * i);
        puts("");
    }else{
        puts("sorry...");
    }
    return 0;
}