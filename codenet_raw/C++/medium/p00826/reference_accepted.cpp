#include <iostream>
#include <iomanip>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <map>
using namespace std;
const double EPS = 1e-8;
const double INF = 1e12;
const double PI = acos(-1);
#define EQ(n,m) (abs((n)-(m)) < EPS)
#define X real()
#define Y imag()

typedef complex<double> P;
typedef vector<P> VP;
struct L : array<P, 2>{
    L(const P& a, const P& b){ at(0)=a; at(1)=b; }
    L(){}
};

namespace std{
    bool operator < (const P& a, const P& b){
        return !EQ(a.X,b.X) ? a.X<b.X : a.Y+EPS<b.Y;
    }
    bool operator == (const P& a, const P& b){
        return abs(a-b) < EPS;
    }
}

double dot(P a, P b){
    return (conj(a)*b).X;
}
double cross(P a, P b){
    return (conj(a)*b).Y;
}
int ccw(P a, P b, P c){
    b -= a;
    c -= a;
    if(cross(b,c) > EPS) return +1; //ccw
    if(cross(b,c) < -EPS) return -1; //cw
    if(dot(b,c) < -EPS) return +2; //c-a-b
    if(abs(c)-abs(b) > EPS) return -2; //a-b-c
    return 0; //a-c-b
}
P unit(const P &p){
    return p/abs(p);
}
P rotate(const P &p, double rad){
    return p *P(cos(rad), sin(rad));
}

bool intersectSS(const L& a, const L& b){
    return ( ccw(a[0],a[1],b[0]) *ccw(a[0],a[1],b[1]) <= 0 ) &&
        ( ccw(b[0],b[1],a[0]) *ccw(b[0],b[1],a[1]) <= 0 );
}
bool intersectSP(const L& s, const P &p){
    return abs(cross(s[0]-p, s[1]-p))<EPS  && dot(s[0]-p, s[1]-p)<EPS;
}

bool isParallel(const P &a, const P &b){
    return abs(cross(a,b)) < EPS;
}
bool isParallel(const L &a, const L &b){
    return isParallel(a[1]-a[0], b[1]-b[0]);
}

P crosspointLL(const L &l, const L &m) {
  double A = cross(l[1]-l[0], m[1]-m[0]);
  double B = cross(l[1]-l[0], l[1]-m[0]);
  return m[0] + B/A *(m[1]-m[0]);
}

double getarea(const VP &poly){
    double ret = 0;
    for (int i=0; i<(int)poly.size(); i++){ 
        ret += cross(poly[i], poly[(i+1)%poly.size()]);
    }
    return ret*0.5;
}

int in_poly(const P &p, const VP &poly){
    int n = poly.size();
    int ret = -1;
    for(int i=0; i<n; i++){
        P a = poly[i]-p;
        P b = poly[(i+1)%n]-p;
        if(a.Y > b.Y) swap(a,b);
        if(intersectSP(L(a,b), P(0,0))) return 0;
        if(a.Y<=0 && b.Y>0 && cross(a,b)<0) ret = -ret;
    }
    return ret;
}

int leftmostpoint(int &pidx, int &cidx, vector<int> &vec, VP &plist){
    P ptoc = plist[cidx] -plist[pidx];
    int nextidx = -1;
    double maxangle = -INF;
    for(int i=0; i<(int)vec.size(); i++){
        P cton = plist[vec[i]] -plist[cidx];
        double angle;
        if(abs(cross(ptoc, cton)) < EPS && dot(ptoc, cton) <EPS){
            angle = -PI;
        }else{
            angle = arg(cton/ ptoc);
        }
        if(angle > maxangle){
            maxangle = angle;
            nextidx = i;
        }
    }
    pidx = cidx;
    cidx = vec[nextidx];
    return nextidx;
}

vector<vector<int> > makeDualGraph(vector<vector<int> > &adj, VP &plist, vector<VP> &vlist){
    map<pair<int,int>, int> edgelist;
    vector<vector<int> > poly;
    vector<vector<bool> > used(adj.size());
    for(int i=0; i<(int)adj.size(); i++){
        used[i] = vector<bool>(adj[i].size(), false);
    }
    vlist = vector<VP>();
      
    int numarea=0;
    for(int i=0; i<(int)adj.size(); i++){
        for(int j=0; j<(int)adj[i].size(); j++){
            if(used[i][j]) continue;
            used[i][j] = true;
            vlist.push_back(VP());
            vector<int> border;
            border.push_back(i);
            vlist[numarea].push_back(plist[i]);
            int prev = i;
            int curr = adj[i][j];
            while(curr!=i){
                border.push_back(curr);
                vlist[numarea].push_back(plist[curr]);
                int idx = leftmostpoint(prev, curr, adj[curr], plist);
                used[prev][idx] = true;
            }
            poly.push_back(border);
            numarea++;
        }
    }
      
    vector<vector<int> > dual(numarea);
    for(int i=0; i<numarea; i++){
        for(int j=0; j<(int)poly[i].size(); j++){
            int a = poly[i][j];
            int b = poly[i][(j+1)%(int)poly[i].size()];
            pair<int,int> key = make_pair(min(a,b), max(a,b));
            if(edgelist.count(key) == 0){
                edgelist[key] = i;
            }else{
                dual[i].push_back(edgelist[key]);
                dual[edgelist[key]].push_back(i);
            }
        }
    }
      
    for(int i=0; i<(int)dual.size(); i++){
        sort(dual[i].begin(), dual[i].end());
        dual[i].erase(unique(dual[i].begin(), dual[i].end()), dual[i].end());
    }
    return dual;
}

pair<vector<vector<int> >, VP> arrangement(const vector<L> &l){
    vector<VP> cp(l.size());
    VP plist;
    for(int i=0; i<(int)l.size(); i++){
        for(int j=i+1; j<(int)l.size(); j++){
            if(!isParallel(l[i], l[j]) && intersectSS(l[i], l[j])){
                P cpij = crosspointLL(l[i], l[j]);
                cp[i].push_back(cpij);
                cp[j].push_back(cpij);
                plist.push_back(cpij);
            }
        }
        cp[i].push_back(l[i][0]);
        cp[i].push_back(l[i][1]);
        plist.push_back(l[i][0]);
        plist.push_back(l[i][1]);
        sort(cp[i].begin(), cp[i].end());
        cp[i].erase(unique(cp[i].begin(), cp[i].end()), cp[i].end());
    }
    sort(plist.begin(), plist.end());
    plist.erase(unique(plist.begin(), plist.end()), plist.end());

    int n = plist.size();
    map<P, int> conv;
    for(int i=0; i<n; i++){
        conv[plist[i]] = i;
    }
    vector<vector<int> > adj(n);
    for(int i=0; i<(int)cp.size(); i++){
        for(int j=0; j<(int)cp[i].size()-1; j++){
            int jidx = conv[cp[i][j]];
            int jp1idx = conv[cp[i][j+1]];
            adj[jidx].push_back(jp1idx);
            adj[jp1idx].push_back(jidx);
        }
    }
    for(int i=0; i<n; i++){
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());
    }
    return make_pair(adj, plist);
}

int main(){
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        vector<L> l(n);
        for(int i=0; i<n; i++){
            double xs,ys,xt,yt;
            cin >> xs >> ys >> xt >> yt;
            l[i] = L(P(xs, ys), P(xt, yt));
        }

        auto ret = arrangement(l);
        auto &adj = ret.first;
        VP &plist = ret.second;
        vector<VP> vlist;
        makeDualGraph(adj, plist, vlist);
        bool ok = false;
        for(const VP &poly: vlist){
            if(getarea(poly) < EPS) continue;
            if(in_poly(P(0, 0), poly) == 1){
                ok = true;
                break;
            }
        }
        if(ok){
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
    }
    return 0;
}
