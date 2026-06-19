#include <bits/stdc++.h>

using namespace std;

char arr[5][5][4];
char puzzle[36][4];
bool used[36];
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

bool check(char a, char b){
  int d = -32;
  return (a + d == b || b + d == a || a == '0' || b == '0');
}

int rec(int y, int x){
  if(y == 4 && x == 1){
    return 1;
  }
  int res = 0;
  for(int i = 0 ; i < 36 ; i++){
    if(used[i]) continue;
    int cnt = 0;
    for(int j = 0 ; j < 4 ; j++){
      arr[y][x][j] = puzzle[i][j];
    }
    for(int j = 0 ; j < 4 ; j++){
      int nx = x + dx[j];
      int ny = y + dy[j];

      if(check(arr[ny][nx][(j+2)%4], arr[y][x][j])){
        cnt++;
      }
    }
    if(cnt == 4){
      int ii = i/4*4;
      for(int j = ii ; j < ii+4 ; j++){
        used[j] = true;
      }
      int a = 0, b = 0;
      if(x == 3) a++;
      if(x > 2) b++;
      res += rec(y + a, x + 1 - 3*b);
      for(int j = ii ; j < ii+4 ; j++){
        used[j] = false;
      }
    }
    for(int j = 0 ; j < 4 ; j++){
      arr[y][x][j] = '0';
    }
  }
  return res;
}

int main(){
  int Tc;
  string str;

  cin >> Tc;
  while(Tc--){
    memset(used, false, sizeof(used));
    fill(arr[0][0], arr[5][5], '0');
    for(int i = 0 ; i < 9 ; i++){
      cin >> str;
      for(int j = 0 ; j < 4 ; j++){
        puzzle[i*4][j] = str[j];
      }
      for(int j = 1 ; j < 4 ; j++){
        for(int k = j ; k < j+4 ; k++){
          puzzle[i*4+j][k-j] = str[k%4];
        }
      }
    }    
    cout << rec(1, 1) << endl;
  }

  return 0;
}