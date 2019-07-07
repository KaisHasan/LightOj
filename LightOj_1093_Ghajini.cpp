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
    int mn , mx , res;
    data(int a = 0, int b = 0,  int c = 0){
        mn = a;
        mx = b;
        res = c;
    }
};

data init(int val){
    return data(val , val , 0);
}

data combine(data a , data b){
    data temp;
    temp.mn = min(a.mn , b.mn);
    temp.mx = max(a.mx , b.mx);
    temp.res = temp.mx - temp.mn;
    return temp;
}

data tree[4 * MAX];
int a[MAX];

void build(int p , int st , int en){
    if(st == en){
        tree[p] = init(a[st]);
        return;
    }
    int md = (st + en)>>1;
    build(p * 2 , st , md);
    build(p * 2 + 1 , md +1 , en);
    tree[p] = combine(tree[p*2] , tree[p*2+1]);
}

data qwr(int p , int st , int en , int l , int r){
    if(st > r || en < l)
        return data(inf , -inf , 0);
    if(st >= l && en <= r)
        return tree[p];
    int md = (st+en)>>1;
    return combine(qwr(p * 2 , st ,md , l , r) , qwr(p * 2 + 1 , md +1  , en , l , r));
}
int n;
int d;
int solve(){
    build(1 , 0 , n - 1);
    int mx = -1;
    int t = d - 1;
    for(int i = t ; i < n ; ++i){
        mx = max(mx , qwr(1 , 0 , n - 1 , i - t , i).res);
    }
    return mx;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
int t;
sc(t);
for(int cases = 1 ; cases <= t ; ++cases){
    sc(n);
    sc(d);
    for(int i = 0 ; i < n ; ++i)
        sc(a[i]);
    printf("Case %d: %d" , cases , solve());
    blank;

}
return 0;
}
