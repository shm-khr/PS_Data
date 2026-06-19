#include <cstdio>
#include <vector>
#include <functional>
#include <array>

using namespace std;

constexpr int mod = 1000000007;

// 二項係数（組み合わせ数）を計算して返す
template <typename T, unsigned int N>
T calcBinomial(int n, int r)
{
    static std::array<std::array<T, (N - 2) / 2>, N - 3> table;
    if (n > N || n < 0 || r < 0 || r > n){ // nかrが範囲外の場合
        return 0;
    }else if (r == 1 || r == n - 1){ // 再帰の終わり
        return n;
    }else if (r == 0 || r == n){
        return 1;
    }else{ // n >= 4 &&  2 <= r <= (n - 2)
        if (r > n / 2) r = n - r; // nCr == nCn-r
        auto &val = table[n - 4][r - 2];
        if (val != 0){ // 既にテーブルに値が乗っている場合
            return val;
        }else{ // 二項係数を再帰的に計算する
            val = (calcBinomial<T, N>(n - 1, r - 1) + calcBinomial<T, N>(n - 1, r)) % mod;
            return val;
        }
    }
}

template <typename T> // 返り値とテーブルの型
class Power3 {
    std::vector<T> table;
public:
    Power3(int max) : table(max) // max:テーブルのサイズ
    {
        table[0] = 3;
        for (int i = 1; i < max; ++i){
            table[i] = (static_cast<long long>(table[i - 1]) * 3) % mod;
        }
    }

    T operator () (int n)
    {
        if (n < 0) return 0;
        if (n == 0) return 1;
        return table[n - 1];
    }
};

int main()
{
    int N, M, K;
    scanf("%d %d %d\n", &N, &M, &K);

    auto nCr = calcBinomial<int, 3000>;
    Power3<int> pow3(2000);

    int result = 0;
    for (int b = 0; b <= M; ++b){
        for (int c = 0; c <= K; ++c){
            result += ((((static_cast<long long>(nCr(N - 1 + b + c, N - 1)) * nCr(b + c, b)) % mod) * pow3(M + K - b - c)) % mod);;
            result %= mod;
        }
    }
    printf("%d\n", result);
}
