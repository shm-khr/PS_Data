#include <stdio.h>
#include <string.h>
#define Int unsigned long long
char ans[2005],T[102][205];int N,M,len[102];bool PtP[102][205];Int dp[2005],RB[26][2005][2],K,lower=1;
int main() {
    scanf("%d %d %llu",&N,&M,&K);dp[0]=1;int i,j,f;for (i=0;i<N;PtP[i++][0]=true) for (j=1;j<205;PtP[i][j++]=false);for (i=0;i<N;i++) {scanf("%s",&T[i]);len[i]=strlen(T[i])-1;} ans[0]='a';
	for (i=1;i<=M;i++) {for (j=0,dp[i]=0;j<N;j++) dp[i]+=(len[j]<i)?dp[i-len[j]-1]:0;if (dp[i]>=K) break;} for (i++;i<=M;dp[i++]=1000000000000000001);if (dp[M]<K) {puts("-");return 0;}for (i=0;i<26;i++) RB[i][0][0]=RB[i][0][1]=1;
    for (i=1;i<M;i++) {for (j=0;j<N;j++) {if (PtP[j][len[j]]) RB[T[j][len[j]]-'a'][i][0]+=RB[ans[i-len[j]-1]-'a'][i-len[j]-1][0];}
        for (j=0;j<N;j++) {for (f=len[j]-1;f>=0;f--) if (i-f-2>=0 && PtP[j][f+1] && RB[ans[i-f-2]-'a'][i-f-2][0]) RB[T[j][f+1]-'a'][i][1]+=dp[M-i-len[j]+f+1]; if (M-i-len[j]>=0 && RB[ans[i-1]-'a'][i-1][0]) RB[T[j][0]-'a'][i][1]+=dp[M-i-len[j]];}
        for (j=0;j<26;j++) if (lower+RB[j][i][1]>K) {ans[i]=j+'a';break;} else lower+=RB[j][i][1];for (j=0;j<N;PtP[j++][0]=true) for (f=len[j]-1;f>=0;f--) PtP[j][f+1]=(PtP[j][f] && ans[i]==T[j][f]);}
	for (j=0;j<N;j++) if (PtP[j][len[j]]) RB[T[j][len[j]]-'a'][i][0]+=RB[ans[M-len[j]-1]-'a'][M-len[j]-1][0];
	for (j=0;j<26;j++) if (lower>K) {ans[M]=j+'a'-1;break;} else if (lower==K && RB[j][i][0]) {ans[M]=j+'a';break;} else lower+=RB[j][i][0];for (i=1;i<=M;printf("%c",ans[i++]));puts("");return 0;}