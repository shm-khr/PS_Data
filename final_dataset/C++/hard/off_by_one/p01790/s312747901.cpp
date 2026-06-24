#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int N, subtree[100000];
char S[100001];
vector< int > g[100000];
deque< int64 > dp[100000][2];
int big[100001];
int64 ret;

void rec(int idx, int par = -1)
{
  subtree[idx] = 1;
  bool button = S[idx] == '(';
  big[idx] = -1;
  for(int i = 0; i < g[idx].size(); i++) {
    if(g[idx][i] == par) continue;
    rec(g[idx][i], idx);
    subtree[idx] += subtree[g[idx][i]];
    if(big[idx] == -1 || dp[g[idx][i]][0].size() < dp[g[idx][big[idx]]][0].size()) big[idx] = i;
  }
  if(~big[idx]) swap(dp[g[idx][big[idx]]], dp[idx]);

  if(dp[idx][button ^ 1].size() > 1) {
    ret += dp[idx][button ^ 1][1];
    dp[idx][button ^ 1].pop_front();
  } else {
    dp[idx][button ^ 1][0] = 0;
  }
  dp[idx][button].push_front(0);
  ++dp[idx][button][1];
  for(int i = 0; i < g[idx].size(); i++) {
    if(g[idx][i] == par || i == big[idx]) continue;
    for(int j = 0; j < dp[g[idx][i]][0].size(); j++) {
      if(j < dp[idx][1].size()) ret += dp[idx][1][j] * dp[g[idx][i]][0][j];
    }
    for(int j = 0; j < dp[g[idx][i]][1].size(); j++) {
      if(j < dp[idx][0].size()) ret += dp[idx][0][j] * dp[g[idx][i]][1][j];
    }
    for(int j = 0; j < dp[g[idx][i]][0].size(); j++) {
      int nextIdx = j + (button ? -1 : 1);
      if(nextIdx < 0) continue;
      while(dp[idx][0].size() <= nextIdx) dp[idx][0].push_back(0);
      dp[idx][0][nextIdx] += dp[g[idx][i]][0][j];
    }
    for(int j = 0; j < dp[g[idx][i]][1].size(); j++) { // '('
      int nextIdx = j + (button ? 1 : -1);
      if(nextIdx < 0) continue;
      while(dp[idx][1].size() <= nextIdx) dp[idx][1].push_back(0);
      dp[idx][1][nextIdx] += dp[g[idx][i]][1][j];
    }
    dp[g[idx][i]][0].clear();
    dp[g[idx][i]][1].clear();
  }
}

int main()
{
  scanf("%d", &N);
  scanf("%s", S);
  for(int i = 0; i < N - 1; i++) {
    int A, B;
    scanf("%d %d", &A, &B);
    --A, --B;
    g[A].push_back(B);
    g[B].push_back(A);
  }
  for(int i = 0; i < N; i++) {
    dp[i][0].push_back(0);
    dp[i][1].push_back(0);
  }
  srand((unsigned) time(NULL));
  rec(rand() % N);
  cout << ret << endl;
}