#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m;cin>>n>>m;
    vector<long long> products(n);for(int i=0;i<n;i++){cin>>products[i];}
    vector<long long> new_price;
    new_price.push_back(0);


    sort(products.rbegin(), products.rend());
    for (int i=0;i<m;i++){
        if (products.size() == 0 || products[0] <= new_price[0]){
            new_price[0] = new_price[0] / 2;
            sort(new_price.rbegin(), new_price.rend());
        } else {
            new_price.insert(new_price.begin(), products[0] / 2);
            sort(new_price.rbegin(), new_price.rend());
            products.erase(products.begin());
        }
    }
    long long acc = 0;
    for (auto p : products){
        acc += p;
    }
    for (auto p : new_price){
        acc += p;
    }
    cout << acc << endl;
    return 0;
}