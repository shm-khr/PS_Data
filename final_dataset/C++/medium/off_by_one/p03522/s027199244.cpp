/*#include<cstdio>
#include<algorithm>
using namespace std;
int w[101000];
int n;
int main(){
    int i;
    
  //  freopen("/Users/joseunghyeon/Downloads/in (2)/eval_input.txt","r",stdin);
    int TC, TT;
    scanf("%d",&TC);
    for(TT=1;TT<=TC;TT++){
        scanf("%d",&n);
        for(i=1;i<=n;i++)scanf("%d",&w[i]);
        sort(w+1,w+n+1);
        printf("Case #%d\n",TT);
        if(w[n]-w[1]>1){
            printf("No\n");
            continue;
        }
        if(w[n]-w[1]==0){
            if(w[1] <= n/2 || w[1] == n-1)printf("Yes\n");
            else printf("No\n");
            continue;
        }
        for(i=1;i<n;i++)if(w[i]!=w[i+1])break;
        int t = i;
        if(t + 1 <= w[n] && t + (n-t)/2 >= w[n])printf("Yes\n");
        else printf("No\n");
    }
}
*/


/*#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000];
int main(){
    char fp[200];
    
    int T[2]={6,18};
    freopen("/Users/joseunghyeon/Downloads/in (2)/eval_input.txt","w",stdout);
    printf("%d\n",T[0]+T[1]);
    for(int TTT = 0; TTT < 2; TTT++){
        for(int TT=0;TT< T[TTT];TT++){
            fprintf(stderr,"%d %d\n",TTT,TT);
            sprintf(fp, "/Users/joseunghyeon/Downloads/in (2)/%d_%02d.txt", TTT, TT);
            freopen(fp, "r",stdin);
            int n, a;
            scanf("%d",&n);
            printf("%d\n",n);
            for(int i=0;i<n;i++){
                scanf("%d",&a);
                printf("%d",a);
                if(i!=n-1)printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
*/

/*#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000];
int main(){
    char fp[200];
    int TC = 0;
    int T[2]={6,18};
    freopen("/Users/joseunghyeon/Downloads/out (2)/eval_output.txt","w",stdout);
    for(int TTT = 0; TTT < 2; TTT++){
        for(int TT=0;TT< T[TTT];TT++){
            fprintf(stderr,"%d %d\n",TTT,TT);
            sprintf(fp, "/Users/joseunghyeon/Downloads/out (2)/%d_%02d.txt", TTT, TT);
            freopen(fp, "r",stdin);
            char rr[10];
            scanf("%s",rr);
            printf("Case #%d\n%s\n",++TC,rr);
        }
    }
    return 0;
}*/

/*
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<vector<int>,int>Map;
vector<int> Do(vector<int>T){
    vector<int>ret,T1,T2;
    if(T.size()==1){
        ret.push_back(T[0]+1);
        return ret;
    }
    int i;
    for(i=0;i<T.size()/2;i++){
        T1.push_back(min(T[i*2],T[i*2+1]));
        T2.push_back(max(T[i*2],T[i*2+1]));
    }
    vector<int>r1, r2;
    r1 = Do(T1);
    r2 = Do(T2);
    for(i=0;i<r1.size();i++)ret.push_back(r1[i]);
    for(i=0;i<r2.size();i++)ret.push_back(r2[i]);
    return ret;
}
int main(){
    int i, w[8];
    vector<int>TP(8);
    vector<int>res;
    for(i=0;i<8;i++)w[i]=i;
    do{
        for(i=0;i<8;i++)TP[i]=w[i];
        res = Do(TP);
        Map[res]  = 1;
    }while(next_permutation(w,w+8));
    for(auto &tp : Map){
        for(i=0;i<8;i++)printf("%d ",tp.first[i]);
        printf("\n");
    }
}*/

#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[201000], Loc[201000], G[201000];
struct point{
    int x, num;
    bool operator<(const point &p)const{
        return x!=p.x?x<p.x:num<p.num;
    }
}ord[210000];
void RTE(){
    RTE();
    RTE();
}
int main(){
    int i, j;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&w[i]);
        Loc[i] = i;
        G[i] = i;
        ord[i] = {w[i],i};
    }
    sort(ord+1,ord+n+1);
    long long res = 0;
    for(i=1;i<=n;i++){
        int t = Loc[ord[i].num];
        int M = 0, Mn = 2e9, xx = 0, U = -1;
        for(j=1;j<=t;j++){
            if(Mn >= max(0,M-ord[i].x)+(t-j)){
                Mn = max(0,M-ord[i].x)+(t-j);
                U = max(M, ord[i].x);
                xx = j;
            }
            M = max(M, w[G[j]]);
        }
        w[ord[i].num] = U;
        res += Mn;
        for(j=t;j>xx;j--){
            swap(G[j-1],G[j]);
            swap(Loc[G[j-1]],Loc[G[j]]);
        }
    }
    printf("%lld\n",res);
}