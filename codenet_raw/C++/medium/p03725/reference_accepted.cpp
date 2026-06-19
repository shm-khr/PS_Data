#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
int main()
{
    int h, w, k;
    cin >> h >> w >> k;
    vector<vector<char>> field(h, vector<char>(w));
    P start;
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> field[i][j];
            if(field[i][j] == 'S') start = P(i, j);
        }
    }
    queue<P> que;
    int dis = min(start.first, start.second);
    dis = min(dis, min(h-1-start.first, w-1-start.second));
    if(dis == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    que.push(start);
    vector<vector<int>> d(h, vector<int>(w, -1));
    d[start.first][start.second] = 0;
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};
    while(!que.empty())
    {
        P p = que.front();
        que.pop();
        int x = p.first;
        int y = p.second;
        dis = min(dis, min(x, y));
        dis = min(dis, min(h-1-x, w-1-y));
        if(d[x][y] == k) continue;
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < h && ny >= 0 && ny < w && field[nx][ny] == '.' && d[nx][ny] == -1)
            {
                que.push(P(nx, ny));
                d[nx][ny] = d[x][y] + 1;
            }
        }
    }
    if(dis == 0) cout << 1 << endl;
    else cout << (dis-1) / k + 2 << endl;
}
