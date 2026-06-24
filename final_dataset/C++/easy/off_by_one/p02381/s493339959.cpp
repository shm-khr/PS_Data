#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int main(){

int i;
double n,score[1000],ave=0,sigma=0;
cin>>n;

for(i=0; i<n; i++){
cin>>score[i];
ave+=score[i];
}

ave/=n;

for(i=0; i<n; i++)sigma+=(score[i]-ave)*(score[i]-ave);

printf("%.8f\n",sqrt(sigma/n));

}