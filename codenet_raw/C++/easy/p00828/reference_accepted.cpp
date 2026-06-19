#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))
using ll = long long;
using P = pair<ll, ll>;
using namespace std;

template<class t> void vin(vector<t>& v, int n) {
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
}

int n, m, p;
int b[10][10][60];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 1, 0, -1, 0 };
int dz[] = { 1, 0, -1, 0 };

bool ok(int x, int y, int z) {
    return 0 <= x and x < n and 0 <= y and y < n and 0 <= z and z < 60;
}

int check(int x, int y, int z, int col, int DX, int DY, int DZ) {
    int ret = 0;
    if (DX == -1) {
        rep(aa, 3) rep(bb, 3) rep(cc, 3) {
            if (aa == bb and bb == cc and aa == 1) continue;
            int nx = x+dx[aa], ny = y+dy[bb], nz = z+dz[cc];
            int nx2 = x+dx[(aa+2)%4], ny2 = y+dy[(bb+2)%4], nz2 = z+dz[(cc+2)%4];
            int tmp = 1;
            if (ok(nx, ny, nz) and b[nx][ny][nz] == col) {
                tmp += check(nx, ny, nz, col, aa, bb, cc) + 1;
            }
            if (ok(nx2, ny2, nz2) and b[nx2][ny2][nz2] == col) {
                tmp += check(nx2, ny2, nz2, col, (aa+2)%4, (bb+2)%4, (cc+2)%4) + 1;
            }
            ret = max(ret, tmp);
        }
    }
    else {
        int nx = x+dx[DX], ny = y+dy[DY], nz = z+dz[DZ];
        if (!ok(nx, ny, nz)) return 0;
        else if (b[nx][ny][nz] == col) {
            return check(nx, ny, nz, col, DX, DY, DZ) + 1;
        }
    }
    return ret;
}

int main() {
    while (cin >> n >> m >> p and (n or m or p)) {
        rep(x, 10) rep(y, 10) rep(z, 60) b[x][y][z] = -1;
        bool end = false;
        rep(i, p) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            for (int z=0; z<10; ++z) {
                if (b[x][y][z] == -1) {
                    b[x][y][z] = i%2;
                    int flag = check(x, y, z, i%2, -1, -1, -1);
                    if (!end and flag >= m) {
                        cout << (i%2 ? "White" : "Black") << ' ' << i+1 << endl;
                        end = true;
                    }
                    break;
                }
            }
        }
        if (!end) {
            cout << "Draw" << endl;
        }
    }
}

