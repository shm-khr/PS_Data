#include<iostream>
#include<complex>
#include<cmath>

int main(void){
    int n;
    while(1){
        int sum=0;
        double s=0;
        std::cin>>n;
        if(!n) break;
        int score[n];
        for(int i=0;i<n;i++){
            std::cin>>score[i];
            sum+=(double)score[i];
        }
        for(int i=0;i<n;i++){
            s+=pow((score[i]-sum/n),2);
        }
        s/=n;
        std::cout<<std::sqrt(s)<<std::endl;
    }
    return 0;
}
