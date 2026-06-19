#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)
#define ALL(C)     (C).begin(),(C).end()
#define pb         push_back

class Tree{
public:
  int value;
  vector<Tree*> child;
  Tree *parent;
  bool iscand;
  Tree(){};
  Tree(int tv,Tree *tp){
    child.clear();
    parent=tp;
    value=tv;
    iscand=false;
    child.pb(tp);
  }
  bool isvalid(int i){
    if (child[i] == NULL || child[i] == parent)return false;
    return true;
  }
  void del(Tree *now){
    rep(i,child.size()){
      if (now == child[i]){
	child.erase(child.begin()+i);
	i--;
      }
    }
  }
  int count_valid(){
    int cnt=0;
    rep(i,child.size()){
      if (isvalid(i))cnt++;
    }
    return cnt;
  }
};

int compute(int n){
  n = 3*n+1;
  while(n%2 == 0)n/=2;
  if (n > 12345678)n-=12345678;
  return n;
}

void update(Tree *now){
  rep(i,now->child.size()){
    if (!now->isvalid(i))continue;
    update(now->child[i]);
  }
  int tmp=now->value;
  now->value=compute(now->value);
  if (now->count_valid() ==0 && tmp < now->value)now->iscand=true;
  else now->iscand=false;
}


void get_all_death(Tree *now,vector<Tree*> &wildel){
  rep(i,now->child.size()){
    if (!now->isvalid(i))continue;
    get_all_death(now->child[i],wildel);
  }
  wildel.pb(now);
}

bool death(Tree *now,vector<Tree*> &wildel){
  if (now->value == 1){
    int cnt = 0;//count child
    Tree *ins=NULL;
    rep(i,now->child.size()){
      if (now->isvalid(i)){
	cnt++;
	ins=now->child[i];
      }
    }
    if (cnt == 1 && now->parent != NULL){
      now->parent->child.pb(ins);//because of chain
      ins->parent=now->parent;
      ins->del(now);
      ins->child.pb(now->parent);

      wildel.pb(now);
    }else get_all_death(now,wildel);
    return true;
  }

  rep(i,now->child.size()){
    if (!now->isvalid(i))continue;
    if (death(now->child[i],wildel)){
      now->child.erase(now->child.begin()+i);
      i--;
    }
  }
  return false;//survive
}

void make_child(Tree *now){
  rep(i,now->child.size()){
    if (!now->isvalid(i))continue;
    make_child(now->child[i]);
  }
  
  if (now->iscand){
    int newvalue = (now->value+1)/2;
    if (newvalue%2 == 0)newvalue++;
    Tree *newnode;
    newnode = new Tree(newvalue,now);
    now->child.pb(newnode);
  }
}

void find_new_leader(Tree *now,int &maxval,int &maxcnt,Tree* &who){
  rep(i,now->child.size()){
    if (!now->isvalid(i))continue;
    find_new_leader(now->child[i],maxval,maxcnt,who);
  }
  
  if (now->value > maxval){
    maxval=now->value;
    maxcnt=1;
    who=now;
  }else if (now->value == maxval)maxcnt++;
}

void replace(Tree *now,Tree *parent){
  if (now == NULL)return;
  replace(now->parent,now);
  now->parent=parent;
}

Tree* find_leader(Tree *root){
  int maxval=0,maxcnt=0;
  Tree *who=NULL;
  find_new_leader(root,maxval,maxcnt,who);
  if (maxcnt == 1){
    replace(who,NULL);
    int newvalue = (who->value+1)/2;
    if (newvalue %2 == 0)newvalue--;

    Tree *bonus;
    bonus=new Tree(newvalue,who);
    who->child.pb(bonus);
    return who;
  }else return root;
}

void travarse(Tree *now){
  cout <<"I'm " << now->value <<" : " <<now <<" " <<  now->parent<<" : ";
  rep(i,now->child.size()){
    //if (!now->isvalid(i))continue;
    if (now->child[i] == now)continue;
    else if (now->child[i] != NULL)cout << now->child[i]->value <<",";
    else cout << now->child[i]<<",";
  }
  cout << endl;
  rep(i,now->child.size()){
    if (!now->isvalid(i))continue;
    travarse(now->child[i]);
  }
}


void del_travarse(Tree *now,vector<Tree*> &wildel){
  rep(i,now->child.size()){
   if (!now->isvalid(i))continue;
   del_travarse(now->child[i],wildel);
  }

  rep(i,wildel.size()){
    now->del(wildel[i]);
  }
}

bool operation_death(Tree *root){
  bool ret=false;
  vector<Tree*> wildel;
  if (death(root,wildel))ret=true;
  //  cout << wildel.size() << endl;
  del_travarse(root,wildel);
  rep(i,wildel.size())free(wildel[i]);
  return ret;
}

void count_node(Tree *now,int &cnt){
  cnt++;
  rep(i,now->child.size()){
   if (!now->isvalid(i))continue;
   count_node(now->child[i],cnt);
  }
}

void solve(int val){
  Tree *root;
  root=new Tree(val,NULL);
  int cnt=1;
  int maxnum=1;
  while(true){
    update(root);

    //    cout <<"update end"<<endl;
    //    travarse(root);cout << endl;

    if (operation_death(root))break;

    //cout <<"death end" << endl;
    //        travarse(root);cout << endl;

    make_child(root);
    //cout << "make_child end" << endl;
    //travarse(root);

    root = find_leader(root);


    int tmp = 0;
    count_node(root,tmp);
    maxnum=max(maxnum,tmp);
    //    cout <<"find leader end" << endl;
    //    travarse(root);cout << endl;
    //break;
    //if (cnt+1 == 105)travarse(root);
    cnt++;
  }
  
  cout << cnt <<" " << maxnum << endl;
  return;
}

main(){
  int n;
  while(cin>>n && n){
    //    cout <<"initial value is " << n << endl;
    solve(n);
  }
}