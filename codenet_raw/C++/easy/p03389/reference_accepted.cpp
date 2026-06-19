#include <iostream>
#include <string>
#include<vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> A(3);
    for (int i = 0; i <3;++i){
        cin>>A[i];
    }
    sort(A.begin(),A.end());
    int count = 0;

    if (A[0]%2 == A[1]%2){
        count += ((A[1]-A[0])/2);
        count+=(A[2]-A[1]);
    }
    else{
        //dai to tyuu guuki onaji
        if(A[2]%2 == A[1]%2){
            count+=1;
            A[2]+=1;A[1]+=1;

            count += ((A[1]-A[0])/2);
            count+=(A[2]-A[1]);
        }
        else{
            count+=1;
            A[2]+=1;A[0]+=1;

            count += ((A[1]-A[0])/2);
            count+=(A[2]-A[1]);

        }
    }

    cout<<count<<endl;

}
