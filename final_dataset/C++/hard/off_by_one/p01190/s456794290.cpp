#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node{
	char dat;
	vector<node*> child;

	node(char d = '_'): dat(d) { }

	bool ambiguous(){
		if(child.size() == 1 && child[0]->child.size() > 1){
			return true;
		}
		for(int i = 0; i < child.size(); ++i){
			if(child[i]->ambiguous()){
				return true;
			}
		}
		return false;
	}

	void print(){
		if(child.empty()){ putchar(dat); }
		else{
			for(int i = 0; i < child.size(); ++i){
				putchar(i ? ' ' : '(');
				child[i]->print();
			}
			putchar(')');
		}
	}
};


node nodes[1000];
const char *ptr;
int k;

node *parse(bool multi = true){
	if(*ptr == 'a'){
		ptr += 10;

		node nd;
		const char *tmp_ptr = ptr;
		int tmp_k = k;

		nd.child.push_back(parse());
		if(!nd.child[0]){
			ptr = tmp_ptr;
			k = tmp_k;
			nd.child[0] = parse(false);
			if(!nd.child[0]){
				return 0;
			}
		}
		
		if(multi){
			while(*ptr == ','){
				ptr += 2;
				tmp_ptr = ptr;
				tmp_k = k;
				nd.child.push_back(parse());

				if((*ptr != ',' && ptr[2] != 'n') || !nd.child.back()){
					ptr = tmp_ptr;
					k = tmp_k;
					nd.child.back() = parse(false);
					if( !nd.child.back() ) return 0;
				}
			}

			if(ptr[2] == 'n'){
				ptr += 5;
				tmp_ptr = ptr;
				tmp_k = k;
				nd.child.push_back(parse());

				if(!nd.child.back()){
					ptr = tmp_ptr;
					k = tmp_k;
					nd.child.back() = parse(false);
					
					if(!nd.child.back()){
						return 0;
					}
				}
			}
			else if(nd.child.size() > 1){
				return 0;
			}
		}
		nodes[++k] = nd;
	}
	else{
		nodes[++k] = node(*ptr++);
	}
	return &nodes[k];
}


int main(){
	int n;
	string s;
	getline(cin, s);
	sscanf(s.c_str(), "%d", &n);

	while(n--){
		getline(cin, s);
		s += "$$$";
		ptr = s.c_str();
		k = 0;

		node *res = parse();
		if(res->ambiguous()){
			puts("AMBIGUOUS");
		}
		else{
			res->print();
			putchar('\n');
		}
	}
}