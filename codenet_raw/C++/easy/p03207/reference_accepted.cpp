/*
  Contest 115
  B - Christmas Eve Eve
  Rakesh Kumar --> 28/09/2020
 */

#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0); std::cout.tie(0);

    int n = 0;
    std::cin >> n;
    int total = 0;
    int max = 0;
    while (n--) {
        int p = 0;
        std::cin >> p;
        max = std::max(p, max);
        total += p;
    }
    total -= max;
    total += max >> 1;
    std::cout << total << std::endl;

    return 0;
}
