#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ms(x) memset(x, 0, sizeof(x))
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    char s[12345];
    int cnt[27];
    while(scanf("%s",s)!=EOF){
            ms(cnt);
        int len = strlen(s), s1 = 0, s2 = 0;
        for(int i=0;i<len;i++){
            cnt[s[i] - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(cnt[i]%2==0 &&cnt[i]!=0) s2++;
            else if(cnt[i]!=0) s1++;
        }
        if(len%2!=0 && s2==0) printf("First\n");
        else if(s1 == s2||(s2==0)) {
            printf("Second\n");
        }
        else printf("First\n");
    }
    return 0;
}
