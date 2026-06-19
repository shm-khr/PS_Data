#include <iostream>

int main(){
  int A, B, C, X, tmpX=0, count=0;

  std::cin >> A;
  std::cin >> B;
  std::cin >> C;
  std::cin >> X;

  for (int i = 0; i < A; i++){
    for (int j = 0; j < B; j++){
      tmpX = i * 500 + j * 100;
      if ((X-tmpX)/50 <= C) count++;
    }
  }

  std::cout << count << '\n';
}