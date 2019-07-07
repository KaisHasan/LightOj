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
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
#define INF 1e9
#define EPS 1e-9
#define NIL 0

vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;



int SIZE;
bitset<600010> isprime;
vi primes;
void seive(int n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(int i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            primes.pb(i);
            for(int j = i + i ; j <= SIZE ; j += i)
                isprime[j] = 0;
        }
    }
}

vi a;
int side[5*MAX];
int loc[5*MAX];
vector< int > G[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] + G1[G[1---n]] + G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

void init(){
    for(int i = 0 ; i <= n + m + 1 ; ++i){
        G[i].clear();
    }
    mem(match,0);
}



int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    int t;
    sc(t);
    int cases = 0;
    seive(500000);
    while(t--){
        int k;
        sc(k);
        n = k;
        a.clear();
        init();
        int mx = -1;
        mem(loc , -1);
        for(int i = 0 ; i < k ; ++i){
            int x;
            sc(x);
            a.pb(x);
            loc[x] = i;
            mx = max(mx , x);
        }
        for(int i = 0 ; i < k ; ++i){
            int u = a[i];
            for(int j = 0 ; j < (int)primes.size() ; ++j){
                ll v = (ll)primes[j] * (ll)u;
                if(v > mx)
                    break;
                if(v >= 5ll * (ll)MAX || loc[(int)v] == -1)
                    continue;
                G[i+1].pb(loc[(int)v] + 1);
                G[loc[(int)v] + 1].pb(i+1);
            }
        }

//        printf("res1 == %d , res2 == %d\n" , res1 , res2);
        int res = n - hopcroft_karp();
        printf("Case %d: %d\n" , ++cases , res);

    }




return 0;
}
