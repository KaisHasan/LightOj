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
#define MP  make_pair
#define mem(a , v)  memset(a , v , sizeof(a))
#define all(v)	((v).begin()), ((v).end())
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf(" %c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;


int tree[4*MAX];
int marked[4*MAX];
string s;
int n;
void build(int p , int st , int en){
    if(st == en){
        tree[p] = s[st] - '0';
        return;
    }
    int md = (st+en)>>1;
    build(p*2 , st , md);
    build(p*2+1 , md + 1 , en);
    tree[p] = 0;
}

void push(int p ){
    if(!marked[p])
        return;
    tree[p*2] += tree[p];
    tree[p*2+1] += tree[p];
    marked[p*2] = marked[p*2+1] = 1;
    tree[p] = 0;
    marked[p] = 0;
}

void update(int p , int st , int en , int l , int r){

    if(st > r || en < l)
        return;

    if(st >= l && en <= r){
        tree[p]++;
        marked[p] = 1;
        return;
    }
    push(p);
    int md = (st+en)>>1;
    update(p*2,st,md,l,r);
    update(p*2+1,md+1,en,l,r);
    tree[p] = 0;
}

int qwr(int p , int st , int en , int pos){

    if(st > pos || en < pos)
        return 0;

    if(st == en){
        return tree[p];
    }
    push(p);
    int md = (st+en)>>1;
    return (qwr(p*2 , st , md , pos) + qwr(p*2+1 , md + 1 , en , pos))%2;
}

void init(){
    build(1 , 0 , n - 1);
    mem(marked,0);
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        cin>>s;
        n = s.size();
        init();
        int q;
        sc(q);
        printf("Case %d:\n" , ++cases);
        while(q--){
            char c;
            sch(c);
            if(c == 'I'){
                int l , r;
                sc(l);sc(r);
                --l;--r;
                update(1 , 0 , n - 1 , l , r);
            }
            else{
                int pos;
                sc(pos);
                int res = qwr(1 , 0 , n - 1 , pos-1)%2;
                printf("%d\n" , res);
            }
        }
    }



return 0;
}
