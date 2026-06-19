#include <iostream>
long long n, m;
int main() {
	std::cin >> n >> m;
	std::cout << (2 * n >= m ? m / 2 : n + (m - 2 * n) / 4);
    return 0;
}