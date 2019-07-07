#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef pair<long long , long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

struct data{
    ll sum , num;
    data(ll _sum = 0 , ll _num = 0){
        sum = _sum;
        num = _num;
    }
};

data tree[4 * MAX];
ll a[MAX];
ll lazy[4 * MAX];

data init(int v){
    data res(v , 1);
    return res;
}

data sum(data a , data b){
    data res(a.sum + b.sum , a.num + b.num);
    return res;
}

void push(int p){
        tree[p*2].sum += lazy[p] * tree[p*2].num;
        lazy[p*2] += lazy[p];
        tree[p*2+1].sum += lazy[p] * tree[p*2+1].num;
        lazy[p*2 + 1] += lazy[p];
        lazy[p] = 0;
}

void build(int p , int st , int en){
    if(st == en){
        tree[p] = init(a[st]);
        return;
    }
    int md = (st + en)>>1;
    build(p * 2 , st , md);
    build(p * 2 + 1 , md + 1, en);
    tree[p] = sum(tree[p*2] , tree[p*2+1]);
}

void update(int p , int st , int en  , int l , int r , int to_add){
    if(st > r || en < l)
        return;
    if(st >= l && en <= r){
        tree[p].sum += to_add * tree[p].num;
        lazy[p] += to_add;
        return;
    }
    push(p);
    int md = (st + en)>>1;
    update(p * 2, st , md , l , r , to_add);
    update(p * 2 + 1 , md +1 , en , l , r , to_add);
    tree[p] = sum(tree[p*2] , tree[p*2+1]);
}

data qwr(int p , int st , int en , int l , int r){
    if(st > r || en < l)
        return data(0 , 0);
    if(st >= l && en <= r)
        return tree[p];
    push(p);
    int md = (st+en)>>1;
    return sum(qwr(p * 2, st , md , l , r) , qwr(p * 2 +1 , md +1 , en , l , r));
}




int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    for(int cases = 1;  cases <= t ; ++cases){
        memset(a , 0 , sizeof(a));
        memset(lazy , 0 , sizeof(lazy));
        int n , q;
        sc(n);sc(q);
        build(1 , 0 , n - 1);
        printf("Case %d:\n" , cases);
        while(q--){
            int k;
            sc(k);
            if(k){
                int x , y;
                sc(x);sc(y);
                ll res = qwr(1 , 0 , n - 1, x , y).sum;
                printf("%lld" , res);
                blank;
            }
            else{
                int x , y , v;
                sc(x);sc(y);sc(v);
                update(1 , 0 , n - 1 ,x , y , v);
            }
        }
       /* if(cases != t)
            blank;*/
    }



return 0;
}
