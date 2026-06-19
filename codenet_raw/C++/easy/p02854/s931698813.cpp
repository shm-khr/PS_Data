#[allow(unused_macros)]
macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        let mut next = || { iter.next().unwrap() };
        input_inner!{next, $($r)*}
    };
    ($($r:tt)*) => {
        let stdin = std::io::stdin();
        let mut bytes = std::io::Read::bytes(std::io::BufReader::new(stdin.lock()));
        let mut next = move || -> String{
            bytes
                .by_ref()
                .map(|r|r.unwrap() as char)
                .skip_while(|c|c.is_whitespace())
                .take_while(|c|!c.is_whitespace())
                .collect()
        };
        input_inner!{next, $($r)*}
    };
}
 
#[allow(unused_macros)]
macro_rules! input_inner {
    ($next:expr) => {};
    ($next:expr, ) => {};
 
    ($next:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($next, $t);
        input_inner!{$next $($r)*}
    };
}
 
#[allow(unused_macros)]
macro_rules! read_value {
    ($next:expr, ( $($t:tt),* )) => {
        ( $(read_value!($next, $t)),* )
    };
 
    ($next:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($next, $t)).collect::<Vec<_>>()
    };
 
    ($next:expr, chars) => {
        read_value!($next, String).chars().collect::<Vec<char>>()
    };
 
    ($next:expr, bytes) => {
        read_value!($next, String).into_bytes()
    };
 
    ($next:expr, usize1) => {
        read_value!($next, usize) - 1
    };
 
    ($next:expr, $t:ty) => {
        $next().parse::<$t>().expect("Parse error")
    };
}
 
use std::cmp::Ordering;
use std::cmp;
use std::cmp::min;
use std::collections::BTreeMap;
use std::process;
use std::cmp::Ord;
use std::collections::HashMap;
use std::collections::HashSet;
use std::collections::VecDeque;
use std::collections::BTreeSet;
use std::mem;
use std::collections::BinaryHeap;
/// Equivalent to std::lowerbound and std::upperbound in c++
pub trait BinarySearch<T> {
    fn lower_bound(&self, &T) -> usize;
    fn upper_bound(&self, &T) -> usize;
}
 
impl<T: Ord> BinarySearch<T> for VecDeque<T>{
    fn lower_bound(&self, x: &T) -> usize {
        let mut low = 0;
        let mut high = self.len();
 
        while low != high {
            let mid = (low + high) / 2;
            match self[mid].cmp(x) {
                Ordering::Less => {
                    low = mid + 1;
                }
                Ordering::Equal | Ordering::Greater => {
                    high = mid;
                }
            }
        }
        low
    }
 
    fn upper_bound(&self, x: &T) -> usize {
        let mut low = 0;
        let mut high = self.len();
 
        while low != high {
            let mid = (low + high) / 2;
            match self[mid].cmp(x) {
                Ordering::Less | Ordering::Equal => {
                    low = mid + 1;
                }
                Ordering::Greater => {
                    high = mid;
                }
            }
        }
        low
    }
}
impl<T: Ord> BinarySearch<T> for [T]{
    fn lower_bound(&self, x: &T) -> usize {
        let mut low = 0;
        let mut high = self.len();
 
        while low != high {
            let mid = (low + high) / 2;
            match self[mid].cmp(x) {
                Ordering::Less => {
                    low = mid + 1;
                }
                Ordering::Equal | Ordering::Greater => {
                    high = mid;
                }
            }
        }
        low
    }
 
    fn upper_bound(&self, x: &T) -> usize {
        let mut low = 0;
        let mut high = self.len();
 
        while low != high {
            let mid = (low + high) / 2;
            match self[mid].cmp(x) {
                Ordering::Less | Ordering::Equal => {
                    low = mid + 1;
                }
                Ordering::Greater => {
                    high = mid;
                }
            }
        }
        low
    }
}

fn matmul(A:&Vec<Vec<i64>>, B:&Vec<Vec<i64>>) -> Vec<Vec<i64>>{
    let mut C = vec![vec![0;B[0].len()];A.len()];
    for i in 0..A.len(){
        for k in 0..B.len(){
            for j in 0..B[0].len(){
                C[i][j] += A[i][k]*B[k][j];
                C[i][j] %= MOD;
            }
        }
    }
    return C;
}
fn matpow(A:&mut Vec<Vec<i64>>, n:usize) -> Vec<Vec<i64>>{
    let mut B = vec![vec![0;A.len()];A.len()];
    for i in 0..A.len(){
        B[i][i] = 1;
    }
    let mut n = n;
    let mut tmp = A.clone();
    while(n>0){
        if n&1 == 1{B = matmul(&B, &tmp);}
        tmp = matmul(&tmp, &tmp);
        n>>=1;
    }
    return B;
}

 
 
 

/*
subset enumeration
let mut set;
let mut subset = set;
        for sm2 in 0..1<<n{
            if subset==0{
                break;
            }

            hogehoge


            subset = (subset-1)&set;
        }
*/
/*
全方位木
    fn dfs(s:usize,bef:usize,m:i64, g:&Vec<Vec<usize>>, dp:&mut Vec<Vec<i64>>)->i64{
        let mut res = 1;
        for i in 0..g[s].len(){
            let e = g[s][i];
            if e != bef{
                dp[s][i] = dfs(e, s, m, g, dp);
                res *= (1 + dp[s][i]);
                res %= m;
            }
        }
        return res;
    }
    let tmp = dfs(0, n, m, &g, &mut dp);
    fn dfs2(s:usize, bef:usize, p:i64, m:i64, g:&Vec<Vec<usize>>, dp:&mut Vec<Vec<i64>>){
        for i in 0..g[s].len(){
            let e = g[s][i];
            if e == bef{dp[s][i] = p;}
        }
        let mut L = vec![0;g[s].len()];
        let mut R = vec![0;g[s].len()];

        for i in 0..g[s].len(){
            L[i] = {
                let mut tmp = 1+dp[s][i];
                tmp %= m;
                if i != 0{
                    tmp *= L[i-1];
                }
                tmp%m
            }
        }

        for i in (0..g[s].len()).rev(){
            if i+1<g[s].len(){
                R[i] = (R[i+1]*((1+dp[s][i])%m))%m;
            }
            else{
                R[i] = (1+dp[s][i])%m;
            }

            if g[s][i] == bef{
                continue;
            }  
            let mut tmp = 1;
            if i != 0{
                tmp *= L[i-1];
                tmp %= m;
            }
            if i+1 != g[s].len(){
                tmp *= R[i+1];
                tmp %= m;
            }
            dfs2(g[s][i], s, tmp, m, g, dp);
        }
    }

    */
fn divisor(n:usize) -> Vec<usize>{
    let mut res:Vec<usize> = Vec::new(); 
    for i in 1..n+1{
        if i*i>n{break;}
        if n%i == 0{
            res.push(i);
            if i != n/i{
                res.push(n/i);    
            }    
        }    
    }
    res
}
struct UnionFind{
    par:Vec<usize>,
    rank:Vec<usize>,
    size:Vec<usize>,
    size_edge:Vec<usize>,
}
impl UnionFind{
    fn init(n:usize) -> UnionFind{
        let mut par = vec![0;n];
        for i in 0..n{
            par[i] = i;
        }
        UnionFind{
            par:par,
            rank:vec![0;n],
            size:vec![1;n],
            size_edge:vec![0;n],
        }
    }
    fn find(&mut self, x:usize) ->usize{
        if(self.par[x] == x){
            x
        }
        else{
            let p = self.par[x];
            let res = self.find(p);
            self.par[x] = res;
            res
        }
    }
    fn same(&mut self, a:usize, b:usize)->bool{
        self.find(a) == self.find(b)
    }
    fn unite(&mut self, a:usize, b:usize){
        let x = self.find(a);
        let y = self.find(b);
        if x != y{
            if (self.rank[x] < self.rank[y]){
                self.par[x] = y;
                self.size[y] += self.size[x];
                self.size_edge[y] += self.size_edge[x];
                self.size_edge[y] += 1;
            }
            else{
                self.par[y] = x;
                self.size[x] += self.size[y];
                self.size_edge[x] += self.size_edge[y];
                self.size_edge[x] += 1;
                if(self.rank[x] == self.rank[y]){ self.rank[x]+=1;}
            }
            
        }
        else{
            self.size_edge[x] += 1;
        }
    }
    fn check_size(&mut self, a:usize) -> usize{
        let x = self.find(a);
        let s = self.size[x];
        s
    }
}
pub mod FenwickTree {
    use std::ops::{AddAssign, Sub};
    pub struct FenwickTree<i64> {
        n: usize,
        data: Vec<i64>,
        init: i64,
    }
 
    impl<i64: Copy + AddAssign + Sub<Output = i64>> FenwickTree<i64> {
        pub fn new(size: usize, init: i64) -> FenwickTree<i64> {
            FenwickTree {
                n: size + 1,
                data: vec![init; size + 1],
                init: init,
            }
        }
 
        pub fn add(&mut self, k: usize, value: i64) {
            let mut x = k;
            while x < self.n {
                self.data[x] += value;
                x |= x + 1;
            }
        }
 
        /// Returns a sum of range `[l, r)`
        pub fn sum(&self, l: usize, r: usize) -> i64 {
            self.sum_one(r) - self.sum_one(l)
        }
 
        /// Returns a sum of range `[0, k)`
        pub fn sum_one(&self, k: usize) -> i64 {
            assert!(k < self.n, "k={} n={}", k, self.n);
 
            let mut result = self.init;
            let mut x = k as i32 - 1;
            while x >= 0 {
                result += self.data[x as usize];
                x = (x & (x + 1)) - 1;
            }
 
            result
        }
    }
}

pub mod FenwickTree_MOD {
    use std::ops::{AddAssign, Sub};
    use std::ops::RemAssign;
    pub struct FenwickTree<i64> {
        n: usize,
        data: Vec<i64>,
        init: i64,
        MOD:  i64,
    }
 
    impl<i64:Copy + AddAssign+ RemAssign + Sub<Output = i64>> FenwickTree<i64> {
        pub fn new(size: usize, init: i64, MOD:i64) -> FenwickTree<i64> {
            FenwickTree {
                n: size + 1,
                data: vec![init; size + 1],
                init: init,
                MOD:MOD,
            }
        }
 
        pub fn add(&mut self, k: usize, value: i64) {
            let mut x = k;
            while x < self.n {
                self.data[x] += value;
                self.data[x] %= self.MOD;
                x |= x + 1;
            }
        }
 
        /// Returns a sum of range `[l, r)`
        pub fn sum(&self, l: usize, r: usize) -> i64 {
            self.sum_one(r) - self.sum_one(l)
        }
 
        /// Returns a sum of range `[0, k)`
        pub fn sum_one(&self, k: usize) -> i64 {
            assert!(k < self.n, "k={} n={}", k, self.n);
 
            let mut result = self.init;
            let mut x = k as i32 - 1;
            while x >= 0 {
                result += self.data[x as usize];
                result %= self.MOD;
                x = (x & (x + 1)) - 1;
            }
 
            result
        }
    }
}
pub struct Scanner<R> {
    stdin: R,
}
 
impl<R: std::io::Read> Scanner<R> {
    pub fn read<T: std::str::FromStr>(&mut self) -> T {
        use std::io::Read;
        let buf = self
            .stdin
            .by_ref()
            .bytes()
            .map(|b| b.unwrap())
            .skip_while(|&b| b == b' ' || b == b'\n' || b == b'\r')
            .take_while(|&b| b != b' ' && b != b'\n' && b != b'\r')
            .collect::<Vec<_>>();
        unsafe { std::str::from_utf8_unchecked(&buf) }
            .parse()
            .ok()
            .expect("Parse error.")
    }
    pub fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.read()).collect()
    }
    pub fn chars(&mut self) -> Vec<char> {
        self.read::<String>().chars().collect()
    }
}
struct LazySegTree<BiOp> {
    n: usize,
    val: Vec<i64>,
    ma:Vec<i64>,
    op: BiOp,
    e: i64,
    upe:i64,
    inf:i64,
}

impl<BiOp> LazySegTree<BiOp>
    where BiOp: Fn(i64, i64) -> i64{
    pub fn new(n_: usize, op: BiOp, e: i64, upe:i64, inf:i64) -> Self {
        let mut n = 1;
        while n < n_ { n *= 2; } // n is a power of 2

        LazySegTree {n: n, val: vec![e; 2 * n ], ma:vec![upe;2*n], op: op, e: e, upe:upe, inf:inf}
    }
    pub fn query(&self, x:usize, y:usize, l:usize, r:usize, k:usize) -> i64 {
        if (r<=x || y<=l) {return self.inf;}
        if (x<=l && r<=y) {return self.ma[k];}
        let mut L = self.query(x,y,l,(l+r)/2, k*2);
        let mut R = self.query(x,y,(l+r)/2,r, k*2+1);
        return self.val[k] + (self.op)(L, R);

    }
    
    pub fn update(&mut self, x:usize, y:usize, v:i64, l:usize,r:usize, k:usize) {
        if (l>=r) {return;}
        if (x<=l && r<=y){
            self.val[k]+=v;
            self.ma[k]+=v;
        }
        else if(l<y && x<r){
            self.update(x, y, v, l, (l+r)/2, k*2);
            self.update(x,y,v,(l+r)/2,r, k*2+1);
            self.ma[k] = self.val[k] + (self.op)(self.ma[k*2], self.ma[k*2+1]);
        }
    }
}
fn lab(a:usize, b:usize, c:&mut usize) -> usize{
    if (b==0){return a;}
    let mut x = c.clone();
    *c = x+1;
    println!("{} {} {}", a,b,c);
    return lab(b, a%b, c);
}
fn dist_1(x0:f64, y0:f64, x1:f64, y1:f64, x2:f64, y2:f64) -> f64{
    let mut a = x2-x1;
    let mut b= y2-y1;
    let mut a2 = a*a;
    let mut b2 = b*b;
    let mut r2 = a2+b2;
    let mut tt = -(a*(x1-x0) + b*(y1-y0));
    if tt<0.0{
        return (x1 - x0)*(x1-x0) + (y1-y0)*(y1-y0);
    }
    if (tt>r2){
        return (x2-x0)*(x2-x0) + (y2-y0)*(y2-y0);
    }
    let mut f1 = a*(y1-y0)-b*(x1-x0);
    return (f1*f1)/r2;
}
fn modinv(a:usize)->usize{
    let mut b = MODu as i64;
    let mut u = 1 as i64;
    let mut v = 0 as i64;
    let mut a = a as i64;
    let mut m = MODu as i64;
    while(b>0){
        let mut t = a/b;
        a -= t*b;
        mem::swap(&mut a, &mut b);
        u-=t*v;
        mem::swap(&mut u, &mut v);    
    }
    u%=m;
    if u<0{u+=m;}
    return u as usize;

}
fn modpow(x:usize, n:usize) -> usize{
        let mut ans = 1;
        let mut n = n;
        let mut x = x;
        while(n != 0){
            if (n&1 == 1){ans = ans*x%MODu;}
            x = x*x%MODu;
            n = n>>1;
        }
        ans
}
fn comb(a:usize, b:usize,  fac:&Vec<usize>, ifac:&Vec<usize>)->usize{
        let mut a = a;
        let mut b = b;
        if a == 0 && b == 0{return 1;}
        if a<b || a<0{return 0;}
        let mut tmp = ifac[a-b]*ifac[b] % MODu;
        return tmp * fac[a] % MODu;
}

fn invs()->(Vec<usize>, Vec<usize>){
    let mut fac = vec![0;300001];
    let mut ifac = vec![0;300001];
    fac[0] = 1;
    ifac[0] = 1;
    for i in 0..300000{
        fac[i+1] = fac[i] * (i+1) % MODu;
        ifac[i+1] = ifac[i] * modpow(i+1, MODu - 2) % MODu;
    }
    (fac, ifac)
}

struct ConvexHallTrick {
    Q: Vec<(i64, i64)>,
}

impl ConvexHallTrick{
    pub fn new() -> Self {

        ConvexHallTrick {Q: Vec::new()}
    }
    pub fn calc(&self, p:(i64, i64), x:i64)->i64{
        return p.0 * x + p.1;
    }
    pub fn dodo(& self, A:(i64, i64), B:(i64, i64), C:(i64, i64)) -> bool{
        //max or min
        (A.1 - C.1) * (B.0 - A.0) <= (A.1 - B.1)*(C.0 - A.0)
    }
    pub fn add(&mut self, a:i64, b:i64){
        self.Q.push((a, b));
        let mut v = self.Q.len();
        while(v >=3 && self.dodo(self.Q[v-3], self.Q[v-2], self.Q[v-1])){
            self.Q[v-2] = self.Q[v-1];
            self.Q.pop();
            v = self.Q.len();
        }
    }
    pub fn query(& self, x:i64) -> i64{
        let mut L = -1;
        let mut R = (self.Q.len() - 1) as i64;
        while(R-L>1){
            let mut m = (L+R)/2;
            if self.calc(self.Q[m as usize], x)>=self.calc(self.Q[m as usize+1], x){
                L=m;
            }
            else{
                R=m;
            }

        }
        return self.calc(self.Q[R as usize], x);
    }
}
#[derive(Eq, PartialEq, Clone, Debug)]
pub struct Rev<T>(pub T);
impl<T: PartialOrd> PartialOrd for Rev<T> {
    fn partial_cmp(&self, other: &Rev<T>) -> Option<Ordering> {
        other.0.partial_cmp(&self.0)
    }
}
impl<T: Ord> Ord for Rev<T> {
    fn cmp(&self, other: &Rev<T>) -> Ordering {
        other.0.cmp(&self.0)
    }
}
fn sieve(n:usize) -> (Vec<bool>, Vec<usize>){
    let mut p:usize = 0;
    let mut is_prime = vec![false; n+1];
    let mut prime = Vec::new();
    for i in 0..n+1{
        is_prime[i] = true;
    }
    is_prime[0] = false;
    is_prime[1] = false;
    for i in 2..n+1{
        if is_prime[i]{
            prime.push(i as usize);
            let mut j = 2*i;
            while(j<=n){
                is_prime[j] = false;
                j+=i;
            }
        }
    }
    (is_prime, prime)
    
}
fn nHr(n:usize, r:usize, fac:&Vec<usize>, ifac:&Vec<usize>) -> usize{
    comb(n + r - 1, r, fac, ifac)
}
fn gcd(a:usize, b:usize)->usize{
    if b==0{return a;}
    return gcd(b, a%b);
}
fn lcm(a:usize, b:usize)->usize{
    return (b/gcd(a, b))*a;
}
struct SegTree_MOD<BiOp> {
    n: usize,
    dat: Vec<i64>,
    op: BiOp,
    e: i64,
    mod_:i64,
}
impl<BiOp> SegTree_MOD<BiOp>
    where BiOp: Fn(i64, i64) -> i64 
          {
    pub fn new(n_: usize, op: BiOp, e: i64, mod_:i64) -> Self {
        let mut n = 1;
        while n < n_ { n *= 2; } // n is a power of 2
        SegTree_MOD {n: n, dat: vec![e; 2 * n - 1], op: op, e: e, mod_:mod_}
    }
    /* ary[k] <- v */
    pub fn update(&mut self, idx: usize, v: i64) {
        let mut k = idx + self.n - 1;
        self.dat[k] = v;
        while k > 0 {
            k = (k - 1) / 2;
            self.dat[k] = (self.op)(self.dat[2 * k + 1], self.dat[2 * k + 2]);
            self.dat[k] %= self.mod_;
        }
    }
    /* [a, b) (note: half-inclusive)
     * http://proc-cpuinfo.fixstars.com/2017/07/optimize-segment-tree/ */
    pub fn query(&self, mut a: usize, mut b: usize) -> i64 {
        let mut left = self.e;
        let mut right = self.e;
        a += self.n - 1;
        b += self.n - 1;
        while a < b {
            if (a & 1) == 0 {
                left = (self.op)(left, self.dat[a]);
                left %= self.mod_;
            }
            if (b & 1) == 0 {
                right = (self.op)(self.dat[b - 1], right);
                right %= self.mod_;
            }
            a = a / 2;
            b = (b - 1) / 2;
        }
        let mut res = (self.op)(left, right);
        res %= self.mod_;
        res
        
    }
}
fn modpow2(x:usize, n:usize) -> usize{
        let mut ans = 1;
        let mut n = n;
        let mut x = x;
        while(n != 0){
            if (n&1 == 1){ans = ans*x%13;}
            x = x*x%13;
            n = n>>1;
        }
        ans
}
#[derive(Clone)]
struct PPUnionFind{
    par:Vec<usize>,
    rank:Vec<usize>,
    time:Vec<usize>,
    now:usize,
    history:Vec<(usize, usize)>,
}
impl PPUnionFind{
    fn init(n:usize) -> PPUnionFind{
        let mut par = vec![0;n];
        for i in 0..n{
            par[i] = i;
        }
        PPUnionFind{
            par:par,
            rank:vec![0;n],
            time:vec![INF as usize;n],
            now:0,
            history:vec![],
        }
    }
    fn find(&mut self, t:usize, x:usize) ->usize{
        if self.time[x] > t{return x;}
        else { let tt = self.par[x]; return self.find(t, tt);}
    }
    fn unite(&mut self, x:usize, y:usize) -> usize{
        self.now+=1;
        let mut x = x;
        let mut y = y;
        let nc = self.now;
        x = self.find(nc, x);
        y = self.find(nc, y);
        if x == y{return self.now;}
        if self.par[x] < self.par[y] {mem::swap(&mut x, &mut y);}
        self.par[x] += self.par[y];
        self.history.push((self.now, self.par[x]));
        self.par[y] = x;
        self.time[y] = self.now;
        return self.now;
    }
}

fn prim(cost:&Vec<Vec<(usize, i64)>>, vs:usize)->i64{
    let mut used = vec![false; vs];
    let mut bh = BinaryHeap::new();
    for j in 0..cost[0].len(){
            bh.push((cost[0][j].1, cost[0][j].0));
    }
    used[0] = true;
    let mut res = 0;
    while(bh.len()!=0){
        let mut m = bh.pop().unwrap();
        if used[m.1]{continue;}
        used[m.1] = true;
        for e in 0..cost[m.1].len(){
            if used[cost[m.1][e].0] == false{
                bh.push((cost[m.1][e].1, cost[m.1][e].0));
            }
        }
        res += m.0;
    }
    return res;
}
fn kruscal(cost:&mut Vec<(i64, usize, usize)>, vs:usize)->i64{
    cost.sort();
    let mut uf = UnionFind::init(vs);
    let mut res = 0;

    for i in 0..cost.len(){
        let e = cost[i].clone();
        if uf.find(e.1) != uf.find(e.2){
            uf.unite(e.1, e.2);
            res += e.0;
        }
    }
    return res;
}
fn kruscal3(cost:&mut Vec<(f64, usize, usize, usize)>, vs:usize)->(UnionFind, Vec<usize>) {
    cost.sort_by(|a, b| (&a.0).partial_cmp(&b.0).unwrap());
    let mut uf = UnionFind::init(vs);
    let mut res = 0.0;
    let mut rv = Vec::new();
    let mut c = 0.0;
    let mut t = 0.0;
    for i in 0..cost.len(){
        let e = cost[i].clone();
        if uf.find(e.1) != uf.find(e.2){
            uf.unite(e.1, e.2);
            rv.push(e.3);
        }
    }
    return (uf,rv);
}
fn kruscal2(cost:&mut Vec<(i64, usize, usize)>, vs:usize)->(i64, UnionFind){
    cost.sort();
    let mut uf = UnionFind::init(vs);
    let mut res = 0;
    let mut tmp = Vec::new();
    for i in 0..cost.len(){
        let e = cost[i].clone();
        if uf.find(e.1) != uf.find(e.2){
            uf.unite(e.1, e.2);
            res += e.0;
            tmp.push(e.0);
            println!("{:?}", e);
        }
    }
    return (res,uf);
}

struct segtree<I, Op>{
    n: usize,
    dat: Vec<I>,
    op:Op,
    e:I,
}
impl<I, Op> segtree<I, Op>


    where Op: Fn(I, I) -> I, I:Copy{
        
        pub fn new(n_:usize, op: Op, e:I)->Self{
            let mut n = 1;
            while(n<n_){n*=2;}
            segtree{n: n, dat:vec![e; 2*n-1], op:op, e:e}
        }
        pub fn update(&mut self, k:usize, a:I){
            let mut k = k;
            k += self.n-1;
            self.dat[k] = a;
            while(k>0){
                k = (k-1)/2;
                self.dat[k] = (self.op)(self.dat[k*2 + 1], self.dat[k*2+2]);
            }
        }
        pub fn query(&self, a:usize, b:usize, k:usize, l:usize, r:usize) -> I{
            if r<=a || b<=l{return self.e;}
            if a<=l && r<=b{return self.dat[k];}
            else{
                let mut vl = self.query(a, b, k*2+1, l, (l+r)/2);
                let mut vr = self.query(a, b, k*2+2, (l+r)/2, r);
                return (self.op)(vl, vr);
            }
        }
    }
struct BIT<I, Op>{
    n:usize,
    bit:Vec<I>,
    op:Op,
    e:I,
    ini:I,
}
impl <I, Op>  BIT<I, Op>
    /* 1-index*/  
    where Op: Fn(I, I) -> I, I:Copy{
        pub fn new(n_:usize, op:Op, e:I, ini:I)->Self{
            BIT{n:n_, bit:vec![e;n_+1], op:op, e:e, ini:ini}
        }
        pub fn sum(&self, i:usize)->I{
            let mut s = self.ini;
            let mut i = i as i64;
            while(i>0){
                s = (self.op)(s, self.bit[i as usize]);
                i -= i & -i;
            }
            return s;
        }
        pub fn add(&mut self, i:usize, x:I){
            let mut i = i as i64;
            while(i<=self.n as i64){
                self.bit[i as usize] = (self.op)(self.bit[i as usize], x);
                i += i & -i;
            }
        }
    }
struct Dsegtree{
    n: usize,
    datA: Vec<i64>,
    datB:Vec<i64>,
    e:i64,
}
impl Dsegtree{
        pub fn new(n_:usize, e:i64)->Self{
            Dsegtree{n:n_, datA:vec![e; n_], datB:vec![e;n_], e:e}
        }
        pub fn update(&mut self,a:usize, b:usize, x:i64,  k:usize, l:usize, r:usize){
            if a<=l && r<=b{
                self.datA[k] += x;
            }
            else if (l<b && a<r){
                self.datB[k] += (cmp::min(b, r) as i64 - cmp::max(a, l) as i64) * x;
                self.update(a, b, x, k*2+1, l, (l+r)/2);
                self.update(a, b, x, k*2+2, (l+r)/2, r);
            }
        }
        pub fn query(&self, a:usize, b:usize, k:usize, l:usize, r:usize) -> i64{
            if (b<=l || r<=a){
                return 0;
            }
            else if (a<=l && r<=b){
                return self.datA[k] * ((r as i64-l as i64)) + self.datB[k];
            }
            else{
                let mut res = (cmp::min(b, r) as i64 - cmp::max(a, l) as i64)* self.datA[k];
                res += self.query(a, b, k*2+1, l, (l+r)/2);
                res += self.query(a, b, k*2+2, (l+r)/2, r);
                return res;
            }
        }
    }
/*
unwrap_or_else
*/
fn prime_factor(n:usize)->HashMap<usize, usize>{
    let mut res = HashMap::new();
    let mut n = n;
    for i in 2..n{
        if i*i>n{break;}
        while(n%i==0){
            *res.entry(i).or_insert(0)+=1;
            n/=i;
        }
    }
    if n != 1{
        res.insert(n, 1);
    }
    res
}
struct rollinghash{
    base:Vec<i64>,
    Mod:Vec<i64>,
    string:Vec<char>,
    hash:Vec<Vec<i64>>,
    power:Vec<Vec<i64>>,
}
impl rollinghash{
    pub fn new(s:&Vec<char>)->Self{
        let mut n = s.len();
        let mut base = vec![1007, 2009];
        let mut hash = vec![vec![0;n+1];2];
        let mut power = vec![vec![1;n+1];2];
        let mut Mod = vec![1000000007, 1000000009];
        for iter in 0..2{
            let mut ht = vec![0;n+1];
            let mut pt = vec![1;n+1];
            for i in 0..n{
                hash[iter][i+1] = (hash[iter][i] * base[iter] + (s[i] as usize) as i64) % Mod[iter];
                power[iter][i+1] = power[iter][i] * base[iter] % Mod[iter];
            }
        }
        return rollinghash{base:base, Mod:Mod, string:s.clone(), hash:hash, power:power}
   
    }
    pub fn get(&self, l:usize, r:usize)->(i64, i64){
        let mut res = self.hash[0][r] - self.hash[0][l] * self.power[0][r-l] % self.Mod[0];
        if res<0{
            res += self.Mod[0];
        }
        let mut res2 = self.hash[1][r] - self.hash[1][l] * self.power[1][r-l] % self.Mod[1];
        if res2<0{
            res2 += self.Mod[1];
        }
        return (res, res2);
    }

}
struct LCA{
    G:Vec<Vec<usize>>,
    parent:Vec<Vec<usize>>,
    depth:Vec<usize>,
    root:usize,
}
impl LCA{
    pub fn new(G:Vec<Vec<usize>>, N:usize)->Self{
        let D = (f64::log2(N as f64)) as usize + 2;
        LCA{G:G, parent:vec![vec![0;N+1];D], depth:vec![0;N+1], root:N}
    }
    pub fn getP(&mut self, v:usize, p:usize, d:usize){
        self.parent[0][v] = p;
        self.depth[v] = d;
        for i in 0..self.G[v].len(){
            if self.G[v][i] != p{
                let n = self.G[v][i];
                self.getP(n, v, d+1);
            }
        }
    }
    pub fn init(&mut self){
        let root = self.root;
        self.getP(root, 0, 0);
        let V = self.depth.len();
        let logN = f64::log2(V as f64) as usize + 2;
        for k in 0..logN-1{
            for v in 1..root+1{
                if self.parent[k][v] == 0{
                    self.parent[k+1][v] = 0;
                }
                else{
                    self.parent[k+1][v] = self.parent[k][self.parent[k][v]];
                }
            }
        }
    }
    fn ft(&self, f:usize, d:usize)->usize{
        let mut now = f;
        let mut now2 = 0;
        let V = self.depth.len();

        let logN = f64::log2(V as f64) as usize + 2;
        let mut v = f;
        for k in 0..logN{
            if (d >> k) & 1 == 1{
                v = self.parent[k][v];
            }
        }

        return v;
    }
    fn lca(&mut self,u:usize, v:usize)->usize{
        let mut u = u;
        let mut v = v;
        if self.depth[u] > self.depth[v]{
            mem::swap(&mut u, &mut v);
        }
        let mut V = self.depth.len();
        let logN = f64::log2(V as f64) as usize + 2;
        for k in 0..logN{
            if ((self.depth[v] - self.depth[u]) >> k)&1 == 1{
                v = self.parent[k][v];
            }
        }
        if u == v{return u;}
        for k in (0..logN).rev(){
            if self.parent[k][u] != self.parent[k][v]{
                u = self.parent[k][u];
                v = self.parent[k][v];
            }
        }
        return self.parent[0][u];
    }
}
fn fast_prime_factor_talbe(ma:usize)->Vec<usize>{
    let mut p = sieve(1001);
    let mut minf = vec![0;ma];
    for j in 0..p.1.len(){
        let P = p.1[j];
        let mut now = P;
        for i in 2..ma{
            if minf[now] ==0{
                minf[now] = P;
            }
            now+=P;
            if now>=ma{
                break;
            }
        }
    }
    return minf;
}
fn area_rectanble(x1:f64, x2:f64, x3:f64, y1:f64, y2:f64, y3:f64)->f64{
    let tmp = x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1;
    tmp.abs()/2.0
}
#[derive(PartialEq, Clone)]
struct FW(f64);

impl Eq for FW {}

impl PartialOrd for FW {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        self.0.partial_cmp(&other.0)
    }
}

impl Ord for FW {
    fn cmp(&self, other: &FW) -> Ordering {
        other.partial_cmp(self).unwrap()

    }
}

fn main(){
    //let sssss = std::io::stdin();
    //let mut sc = Scanner { stdin: sssss.lock() };
    input!{
        N:usize,
        A:[usize;N],
    }
    let mut res=  INF as usize;
    fn x(a:usize, b:usize)->usize{
        a+b
    }
    let mut st = segtree::new(N, x, 0);
    for i in 0..N{
            st.update(i, A[i]);
    }
    let mut st2 = segtree::new(N, x, 0);
    for i in 0..N{
        if A[i] >2{
            st2.update(i, A[i]-2);
        }
    }

    for i in 0..N-1{
        let mut a = st.query(0, i+1, 0, 0, st.n);
        let mut b = st.query(i+1, N, 0, 0, st.n);
        if a>b{
            res = cmp::min(res, (a-b - 1)/ (N-i-1) + 1);
        }
        else if a<b{
            res = cmp::min(res, (b-a - 1)/ (i+1) + 1);
        }
        else{
            res = 0;
        }
    }
    println!("{}", res);
}

pub static MOD:i64 = 1000000007;
pub static MODu:usize = 998244353;
pub static eps:f64 = 1e-6;
const INF: i64 = 1 << 60;



