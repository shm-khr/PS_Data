#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>
#include <map>
#include <string>
#include <cstring>
#include <set>
#include <deque>
#include <bitset>
#include <list>
#include <cctype>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair <int,int> P;
typedef pair <int,P > PP;

int tx[] = {0,1,0,-1};
int ty[] = {-1,0,1,0};

static const double EPS = 1e-8;

int gSum = 0;

class Piece{
public:
	int pos[4];
	Piece(){
		memset(pos,0,sizeof(pos));
	}
};

bool check(int pos,int key[24]){
	if(pos == 0) return true;
	//012
	//345
	//678

	else if(pos==1){
		return (key[0] + key[1]==0);
	}

	else if(pos==2){
		return  (key[2] + key[3]==0);
	}

	else if(pos==3){
		return (key[4] + key[7]==0);
	}

	else if(pos==4){
		return ((key[5] + key[8]==0)
		&& (key[10] + key[11]==0));
	}
	else if(pos==5){
		return ((key[6] + key[9]==0)
			&& (key[12] + key[13]==0));
	}

	else if(pos==6){
		return (key[14] + key[17]==0);
	}

	else if(pos==7){
		return ((key[15] + key[18]==0)
			&& (key[20] + key[21]==0));
	}

	else if(pos==8){
		return ((key[16] + key[19]==0)
			&& (key[22] + key[23]==0));
	}
	else{
		return false;
	}
}

void dfs(int key[24],int state,Piece* puzzle){
	if(state==9){
		gSum++;
		return;
	}

	int res = 0;
	if(state==0){
		key[0] = puzzle[0].pos[0];
		key[4] = puzzle[0].pos[1];
		dfs(key,1,puzzle);
		key[0] = puzzle[0].pos[1];
		key[4] = puzzle[0].pos[2];
		dfs(key,1,puzzle);
		key[0] = puzzle[0].pos[2];
		key[4] = puzzle[0].pos[3];
		dfs(key,1,puzzle);
		key[0] = puzzle[0].pos[3];
		key[4] = puzzle[0].pos[0];
		dfs(key,1,puzzle);
	}
	else if(state==1){
		
		key[2] = puzzle[1].pos[0];
		key[5] = puzzle[1].pos[1];
		key[1] = puzzle[1].pos[2];
		if(check(1,key)) dfs(key,2,puzzle);

		key[2] = puzzle[1].pos[1];
		key[5] = puzzle[1].pos[2];
		key[1] = puzzle[1].pos[3];
		if(check(1,key)) dfs(key,2,puzzle);

		key[2] = puzzle[1].pos[2];
		key[5] = puzzle[1].pos[3];
		key[1] = puzzle[1].pos[0];
		if(check(1,key)) dfs(key,2,puzzle);

		key[2] = puzzle[1].pos[3];
		key[5] = puzzle[1].pos[0];
		key[1] = puzzle[1].pos[1];
		if(check(1,key)) dfs(key,2,puzzle);
	}
	else if(state==2){	
		key[6] = puzzle[2].pos[0];
		key[3] = puzzle[2].pos[1];
		if(check(2,key)) dfs(key,3,puzzle);
		key[6] = puzzle[2].pos[1];
		key[3] = puzzle[2].pos[2];
		if(check(2,key)) dfs(key,3,puzzle);
		key[6] = puzzle[2].pos[2];
		key[3] = puzzle[2].pos[3];
		if(check(2,key)) dfs(key,3,puzzle);
		key[6] = puzzle[2].pos[3];
		key[3] = puzzle[2].pos[0];
		if(check(2,key)) dfs(key,3,puzzle);
	}
	else if(state==3){
		key[7] = puzzle[3].pos[0];
		key[10] = puzzle[3].pos[1];
		key[14] = puzzle[3].pos[2];
		if(check(3,key)) dfs(key,4,puzzle);

		key[7] = puzzle[3].pos[1];
		key[10] = puzzle[3].pos[2];
		key[14] = puzzle[3].pos[3];
		if(check(3,key)) dfs(key,4,puzzle);

		key[7] = puzzle[3].pos[2];
		key[10] = puzzle[3].pos[3];
		key[14] = puzzle[3].pos[0];
		if(check(3,key)) dfs(key,4,puzzle);

		key[7] = puzzle[3].pos[3];
		key[10] = puzzle[3].pos[0];
		key[14] = puzzle[3].pos[1];
		if(check(3,key)) dfs(key,4,puzzle);
	}
	else if(state==4){
		key[8] = puzzle[4].pos[0];
		key[12] = puzzle[4].pos[1];
		key[15] = puzzle[4].pos[2];
		key[11] = puzzle[4].pos[3];
		if(check(4,key)) dfs(key,5,puzzle);

		key[8] = puzzle[4].pos[1];
		key[12] = puzzle[4].pos[2];
		key[15] = puzzle[4].pos[3];
		key[11] = puzzle[4].pos[0];
		if(check(4,key)) dfs(key,5,puzzle);

		key[8] = puzzle[4].pos[2];
		key[12] = puzzle[4].pos[3];
		key[15] = puzzle[4].pos[0];
		key[11] = puzzle[4].pos[1];
		if(check(4,key)) dfs(key,5,puzzle);

		key[8] = puzzle[4].pos[3];
		key[12] = puzzle[4].pos[0];
		key[15] = puzzle[4].pos[1];
		key[11] = puzzle[4].pos[2];
		if(check(4,key)) dfs(key,5,puzzle);
	}
	else if(state==5){
		key[16] = puzzle[5].pos[0];
		key[13] = puzzle[5].pos[1];
		key[9] = puzzle[5].pos[2];
		if(check(5,key)) dfs(key,6,puzzle);

		key[16] = puzzle[5].pos[1];
		key[13] = puzzle[5].pos[2];
		key[9] = puzzle[5].pos[3];
		if(check(5,key)) dfs(key,6,puzzle);

		key[16] = puzzle[5].pos[2];
		key[13] = puzzle[5].pos[3];
		key[9] = puzzle[5].pos[0];
		if(check(5,key)) dfs(key,6,puzzle);

		key[16] = puzzle[5].pos[3];
		key[13] = puzzle[5].pos[0];
		key[9] = puzzle[5].pos[1];
		if(check(5,key)) dfs(key,6,puzzle);
	}
	else if(state==6){
		key[17] = puzzle[6].pos[0];
		key[20] = puzzle[6].pos[1];
		if(check(6,key)) dfs(key,7,puzzle);

		key[17] = puzzle[6].pos[1];
		key[20] = puzzle[6].pos[2];
		if(check(6,key)) dfs(key,7,puzzle);

		key[17] = puzzle[6].pos[2];
		key[20] = puzzle[6].pos[3];
		if(check(6,key)) dfs(key,7,puzzle);

		key[17] = puzzle[6].pos[3];
		key[20] = puzzle[6].pos[0];
		if(check(6,key)) dfs(key,7,puzzle);
	}
	else if(state==7){
		key[21] = puzzle[7].pos[0];
		key[18] = puzzle[7].pos[1];
		key[22] = puzzle[7].pos[2];
		if(check(7,key)) dfs(key,8,puzzle);		

		key[21] = puzzle[7].pos[1];
		key[18] = puzzle[7].pos[2];
		key[22] = puzzle[7].pos[3];
		if(check(7,key)) dfs(key,8,puzzle);	

		key[21] = puzzle[7].pos[2];
		key[18] = puzzle[7].pos[3];
		key[22] = puzzle[7].pos[0];
		if(check(7,key)) dfs(key,8,puzzle);	

		key[21] = puzzle[7].pos[3];
		key[18] = puzzle[7].pos[0];
		key[22] = puzzle[7].pos[1];
		if(check(7,key)) dfs(key,8,puzzle);	
	}
	else if(state==8){
		key[23] = puzzle[8].pos[0];
		key[19] = puzzle[8].pos[1];
		if(check(8,key)) dfs(key,9,puzzle);	

		key[23] = puzzle[8].pos[1];
		key[19] = puzzle[8].pos[2];
		if(check(8,key)) dfs(key,9,puzzle);	

		key[23] = puzzle[8].pos[2];
		key[19] = puzzle[8].pos[3];
		if(check(8,key)) dfs(key,9,puzzle);	

		key[23] = puzzle[8].pos[3];
		key[19] = puzzle[8].pos[0];
		if(check(8,key)) dfs(key,9,puzzle);	
	}
}

char table[256];

int main(){
	int n;

	table['r'] = 1;
	table['g'] = 2;
	table['b'] = 3;
	table['w'] = 4;
	table['R'] = -1;
	table['G'] = -2;
	table['B'] = -3;
	table['W'] = -4;

	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){

			Piece puzzle[9];
			for(int j=0;j<9;j++){
				string str;
				cin >> str;
				for(int k=0;k<4;k++){
					puzzle[j].pos[k] = table[str[k]];
				}
			}

			int patterns[] = {0,1,2,3,4,5,6,7,8};

			int key[24];
			memset(key,-1,sizeof(key));

			int res = 0;
			gSum = 0;

			do{
				Piece tmp[9];
				for(int i=0;i<9;i++){
					tmp[i] = puzzle[patterns[i]];
				}
				dfs(key,0,tmp);
			}while(next_permutation(patterns,patterns+9));

			printf("%d\n",gSum);
		}
	}
}