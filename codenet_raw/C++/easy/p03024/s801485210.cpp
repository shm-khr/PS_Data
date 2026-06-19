#include <bits/stdc++.h>
using namespace std;
std::string replaceAll(std::string &replacedStr, std::string from, std::string to) {
    unsigned int pos = replacedStr.find(from);
    int toLen = to.length();
 
    if (from.empty()) {
        return replacedStr;
    }
 
    while ((pos = replacedStr.find(from, pos)) != std::string::npos) {
        replacedStr.replace(pos, from.length(), to);
        pos += toLen;
    }
    return replacedStr;
}
int main() {


//long long a,b;
//int *num=new int[4];
//char *s=new char[3];
string s;
cin >> s;
int res=0;
for(int i=0;i<s.length();i++){
if(s[i]=='o')res++;
}
if(res>=7)
cout << "YES"<<"\n";
else
cout << "NO"<<"\n";


}
