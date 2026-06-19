#include <iostream>
#include<algorithm>

using namespace std;

const int N = 2*1e5+5;
const int MAX = 1e6+5;
int n;
bool danhDau[MAX];
int arr[N];

bool mark[MAX];

void Danhdau(bool danhDau[], int num){
    mark[num] = true;
    for(int i=num;i<MAX;i+=num){
        danhDau[i]=true;
    }
}

int main()
{
    int i, count=0;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>arr[i];
    sort(arr+1,arr+1+n);
    for(i=1;i<=n;i++){
        if(danhDau[arr[i]]==false){
             if(arr[i]==arr[i+1]){
                if (mark[arr[i]] == false) Danhdau(danhDau,arr[i]);
                continue;
             }
             count++;
        }
        if (mark[arr[i]] == false) Danhdau(danhDau,arr[i]);
    }
    cout<<count;
    return 0;
}
