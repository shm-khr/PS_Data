#include <iostream>
#include <map>

int main() {
  std::string in;
  std::cin >> in;
  std::map<char,int> words;
  int num = 0;

  for(int i = 0; i < in.length(); i++) {
    if(words.find(in[i]) != words.end())
      num++;
    else
      words[in[i]] = 0;
  }

  if(num % 2 == 0)
    std::cout << "First" << std::endl;
  else
    std::cout << "Second" << std::endl;
}
