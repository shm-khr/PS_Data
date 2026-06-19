#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int main(){
    
    string d;
    string e;
    
    
    int n=0;
    scanf("%d",&n);
    
    for(int i=0; i<n; i++){
        int f[81]={0};
        int g[81]={0};
        int h[81]={0};
        
        cin>>d;
        cin>>e;
        
        if((int)d.length()>80||(int)e.length()>80){
            printf("overflow\n");
        }else{
            int j=80;
            for(int i=(int)d.length()-1; i>=0; i--){
                f[j] = (d[i]-'0');
                j--;
            }
            j=80;
            for(int i=(int)e.length()-1; i>=0; i--){
                g[j] = (e[i]-'0');
                j--;
            }
            
//            for(int i=0; i<81; i++){
//                printf("%d",f[i]);
//            }
//            printf("\n");
//            
//            for(int i=0; i<81; i++){
//                printf("%d",g[i]);
//            }
//            printf("\n");
            
            int temp=0;

            for(int i=80; i>=0; i--){
                temp = temp + f[i] + g[i];
                h[i] = temp % 10;
                temp = temp / 10;
            }
            j=0;
            if(h[j]!=0){
                printf("overflow\n");
            }else{
                while(h[j]==0){
                    j++;
                }
                if(j==165){
                    printf("0");
                }else{
                    for(int i=j; i<81; i++){
                        printf("%d",h[i]);
                    }
                }
            }
            printf("\n");
        }
        
        
        
    }
return 0;
    
    
}